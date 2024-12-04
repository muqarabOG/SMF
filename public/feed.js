// Toggle dark mode
function toggleDarkMode() {
    document.body.classList.toggle("dark-mode");
    localStorage.setItem("darkMode", document.body.classList.contains("dark-mode"));
}

// Check if dark mode is enabled on page load
if (localStorage.getItem("darkMode") === "true") {
    document.body.classList.add("dark-mode");
}

// Display posts
function displayPosts(posts) {
    const postsContainer = document.getElementById('posts');
    postsContainer.innerHTML = ''; // Clear previous posts

    posts.forEach(post => {
        const postDiv = document.createElement('div');
        postDiv.classList.add('post');

        postDiv.innerHTML = `
            <div class="header">
                <img src="default-avatar.png" alt="${post.username}'s Avatar" class="avatar">
                <span><strong>${post.username}</strong></span>
            </div>
            <div class="content">${post.content}</div>
            <div class="actions">
                <button class="like-btn" onclick="likePost(${post.postId})">Like (${post.likes})</button>
                <button class="comment-btn" onclick="commentPost(${post.postId})">Comment</button>
            </div>
        `;

        postsContainer.appendChild(postDiv);
    });
}

// Fetch posts and display them
function fetchPosts() {
    fetch('http://127.0.0.1:5000/getPosts', {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json'
        }
    })
    .then(response => response.json())
    .then(data => displayPosts(data))
    .catch(error => console.error('Error:', error));
}

// Like a post
function likePost(postId) {
    fetch('http://127.0.0.1:5000/likePost', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ postId })
    })
    .then(response => response.json())
    .then(data => {
        alert('Liked Post!');
        fetchPosts(); // Refresh posts after liking
    })
    .catch(error => console.error('Error:', error));
}

// Comment on a post
function commentPost(postId) {
    const comment = prompt('Enter your comment:');
    if (comment) {
        fetch('http://127.0.0.1:5000/commentPost', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ postId, comment })
        })
        .then(response => response.json())
        .then(data => {
            alert('Comment added!');
            fetchPosts(); // Refresh posts after commenting
        })
        .catch(error => console.error('Error:', error));
    }
}

// Create a new post
document.getElementById('create-post').addEventListener('click', function() {
    const content = document.getElementById('new-post').value;
    const username = localStorage.getItem('username');

    if (!content) {
        alert('Post content cannot be empty!');
        return;
    }

    fetch('http://127.0.0.1:5000/createPost', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ username, content })
    })
    .then(response => response.json())
    .then(data => {
        // Add the new post to the feed
        fetchPosts(); // Refresh posts
        document.getElementById('new-post').value = ''; // Clear input
    })
    .catch(error => console.error('Error:', error));
});

// Initial load of posts
fetchPosts();
