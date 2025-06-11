# Task6: Web Scraper Server

## Description
This is a Node.js Express server that serves static web files and provides an API endpoint to scrape paragraph texts from a given URL. The server uses `axios` to fetch HTML content and `cheerio` to parse and extract data.

## Main File
- `server.js`
- Static files in the `public` directory (`index.html`, `script.js`, `style.css`)

## How to Run
1. Navigate to the `Task6` directory.
2. Install dependencies:
   ```
   npm install
   ```
3. Start the server:
   ```
   node server.js
   ```
4. Open a web browser and go to:
   ```
   http://localhost:3000
   ```
5. Use the web interface to enter a URL and scrape paragraph texts.

## Notes
- The server listens on port 3000.
- The `/scrape` endpoint accepts POST requests with a JSON body containing the `url` to scrape.
- The web interface is served from the `public` folder.
- Ensure Node.js and npm are installed before running.
