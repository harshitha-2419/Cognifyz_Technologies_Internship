document.getElementById('scrape-form').addEventListener('submit', async (e) => {
  e.preventDefault();
  const urlInput = document.getElementById('url-input');
  const url = urlInput.value.trim();
  const dataList = document.getElementById('data-list');
  dataList.innerHTML = '';

  if (!url) {
    alert('Please enter a valid URL');
    return;
  }

  try {
    const response = await fetch('/scrape', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({ url })
    });

    if (!response.ok) {
      throw new Error('Failed to fetch scraped data');
    }

    const data = await response.json();
    if (data.error) {
      alert(data.error);
      return;
    }

    if (data.paragraphs.length === 0) {
      dataList.innerHTML = '<li>No paragraphs found.</li>';
      return;
    }

    // Limit to max 10 paragraphs
    const maxItems = 10;
    // Filter out empty paragraphs
    const filteredParagraphs = data.paragraphs.filter(p => p.trim() !== '');
    filteredParagraphs.slice(0, maxItems).forEach((text, index) => {
      const li = document.createElement('li');
      li.textContent = text;
      li.style.setProperty('--delay', `${index * 0.1}s`);
      dataList.appendChild(li);
    });
    // Add a break line after the list
    const br = document.createElement('br');
    dataList.appendChild(br);

    
  } catch (error) {
    alert('Error: ' + error.message);
  }
});
