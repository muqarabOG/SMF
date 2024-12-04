document.getElementById('login-btn').addEventListener('click', function() {
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    fetch('http://127.0.0.1:5000/login', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ username, password })
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            localStorage.setItem('username', data.username);
            window.location.href = 'feed.html'; // Redirect to the feed page
        } else {
            alert(data.message);
        }
    })
    .catch(error => console.error('Error:', error));
});
