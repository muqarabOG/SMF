from flask import Flask, request, jsonify
from flask_cors import CORS
import json

app = Flask(__name__)
CORS(app)

# Mock database for users and posts
users = {}
posts = []

# Route to register a new user
@app.route('/register', methods=['POST'])
def register():
    data = request.get_json()

    # Check if the username already exists
    if data['username'] in users:
        return jsonify({'success': False, 'message': 'Username already exists'}), 400

    # Store the user in the mock database
    users[data['username']] = {
        'password': data['password'],
        'email': data['email'],
        'avatar': 'default-avatar.png'  # Default avatar for now
    }

    return jsonify({'success': True, 'message': 'User registered successfully'}), 201

# Route to login
@app.route('/login', methods=['POST'])
def login():
    data = request.get_json()

    # Check if the username exists
    if data['username'] in users:
        # Check if the password is correct
        if users[data['username']]['password'] == data['password']:
            return jsonify({'success': True, 'message': 'Login successful', 'username': data['username']}), 200
        else:
            return jsonify({'success': False, 'message': 'Invalid password'}), 401
    else:
        return jsonify({'success': False, 'message': 'Username not found'}), 404

# Route to create a post
@app.route('/createPost', methods=['POST'])
def create_post():
    data = request.get_json()

    # Ensure that the user exists
    if data['username'] not in users:
        return jsonify({'success': False, 'message': 'User not found'}), 404

    new_post = {
        'postId': len(posts) + 1,
        'username': data['username'],
        'content': data['content'],
        'likes': 0,
        'comments': [],
    }
    posts.append(new_post)
    return jsonify(new_post), 201

# Route to get all posts
@app.route('/getPosts', methods=['GET'])
def get_posts():
    return jsonify(posts), 200

# Route to like a post
@app.route('/likePost', methods=['POST'])
def like_post():
    data = request.get_json()
    post_id = data['postId']

    for post in posts:
        if post['postId'] == post_id:
            post['likes'] += 1
            return jsonify(post), 200
    return jsonify({'message': 'Post not found'}), 404

# Route to add comment
@app.route('/commentPost', methods=['POST'])
def comment_post():
    data = request.get_json()
    post_id = data['postId']
    comment = data['comment']
    
    for post in posts:
        if post['postId'] == post_id:
            post['comments'].append(comment)
            return jsonify(post), 200
    return jsonify({'message': 'Post not found'}), 404

if __name__ == '__main__':
    app.run(debug=True, port=5000)
