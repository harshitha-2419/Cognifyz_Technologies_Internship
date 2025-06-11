const express = require('express');
const axios = require('axios');
const cheerio = require('cheerio');
const path = require('path');

const app = express();
const PORT = 3000;

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

app.post('/scrape', async (req, res) => {
  const { url } = req.body;
  if (!url) {
    return res.status(400).json({ error: 'URL is required' });
  }

  try {
    const response = await axios.get(url);
    const html = response.data;
    const $ = cheerio.load(html);

    // Example: scrape all paragraph texts
    const paragraphs = [];
    $('p').each((i, elem) => {
      paragraphs.push($(elem).text().trim());
    });

    res.json({ paragraphs });
  } catch (error) {
    res.status(500).json({ error: 'Failed to fetch or parse the URL' });
  }
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
