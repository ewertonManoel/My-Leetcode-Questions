const express = require('express');
const cors = require('cors');
const fs = require('fs');
const { execSync } = require('child_process');

const app = express();
app.use(cors());
app.use(express.json());

app.post('/salvar', (req, res) => {
    let { title } = req.body;
    const { code } = req.body;
    
    title = title.trim().replace(/\s+/g, '-');

    if (!title.match(/\.[a-zA-Z0-9]+$/)) {
        title = `${title}.cpp`;
    }

    try {
        fs.writeFileSync(title, code);
        console.log(`\n[INFO] File created locally: ${title}`);

        execSync(`git add "${title}"`);
        execSync(`git commit -m "feat: add solution for ${title}"`);
        execSync(`git push`);
        console.log(`[SUCCESS] Successfully pushed to GitHub.`);

        res.status(200).json({ success: true });
    } catch (error) {
        console.error("[ERROR] Git execution failed:", error.message);
        res.status(500).json({ error: error.message });
    }
});

app.listen(3000, () => {
    console.log('[INFO] LeetCode-to-Git server is running on port 3000. Default extension: C++');
});