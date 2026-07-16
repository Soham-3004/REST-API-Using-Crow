# REST API Learning Project

A lightweight **User Management System** built using **C++**, **Crow**, and a simple **HTML/CSS/JavaScript** frontend. The project demonstrates the fundamentals of RESTful API development by implementing a complete CRUD application from scratch.

## Features

### Backend (C++ + Crow)

* RESTful API built with the Crow framework
* Full CRUD operations

  * **GET** – Retrieve all users or a single user
  * **POST** – Create a new user
  * **PUT** – Update an existing user
  * **DELETE** – Delete a user
* JSON request and response handling
* CORS middleware for frontend communication
* Modular project structure
* In-memory user storage using `std::map`

### Frontend (HTML/CSS/JavaScript)

* Displays all users in a dynamic table
* Add new users
* Edit existing users inline
* Delete users
* Automatically refreshes the UI after every operation
* Communicates with the backend using the Fetch API

---

## Project Structure

```text
rest-api-learning/
│
├── build/
├── frontend/
│   ├── index.html
│   ├── style.css
│   └── script.js
│
├── include/
│   ├── cors_middleware.h
│   ├── json_utils.h
│   ├── routes.h
│   └── user.h
│
├── src/
│   ├── json_utils.cpp
│   ├── main.cpp
│   └── routes.cpp
│
├── CMakeLists.txt
├── README.md
└── .gitignore
```

---

## Technologies Used

* C++17
* Crow Framework
* CMake
* HTML5
* CSS3
* JavaScript (ES6)
* Fetch API
* JSON

---

## API Endpoints

| Method | Endpoint      | Description              |
| ------ | ------------- | ------------------------ |
| GET    | `/`           | Welcome route            |
| GET    | `/about`      | About endpoint           |
| GET    | `/skills`     | Sample JSON response     |
| GET    | `/users`      | Retrieve all users       |
| GET    | `/users/<id>` | Retrieve a specific user |
| POST   | `/users`      | Create a new user        |
| PUT    | `/users/<id>` | Update a user            |
| DELETE | `/users/<id>` | Delete a user            |

---

## Current Architecture

```text
Frontend (HTML/CSS/JavaScript)
            │
            ▼
      REST API (Crow)
            │
            ▼
 In-Memory Database (std::map)
```

---

## What I Learned

During this project I explored:

* REST API fundamentals
* HTTP methods (GET, POST, PUT, DELETE)
* RESTful route design
* JSON serialization and deserialization
* CORS middleware
* Fetch API
* DOM manipulation
* Dynamic table rendering
* Event handling
* Modular C++ project organization
* Client–server communication

---

## Future Improvements

Planned enhancements include:

* Replace the in-memory `std::map` with **SQLite** for persistent storage
* Introduce a repository/database layer to separate routing from data access
* Input validation on both frontend and backend
* Better error handling and user feedback
* Improved UI styling and responsive layout
* Search and filter functionality
* Pagination for larger datasets
* Logging and request monitoring
* Unit tests for API endpoints
* Docker support for easier deployment

---

## Build

```bash
mkdir build
cd build
cmake ..
make
./rest_api
```

The backend runs on:

```
http://localhost:18080
```

Serve the frontend using a local web server (for example, the VS Code Live Server extension), then open:

```
http://localhost:5500
```

---

## Project Status

**Current Version:** Complete CRUD application with a modular C++ backend and JavaScript frontend.

**Next Milestone:** Replace the in-memory data store with SQLite to provide persistent storage while keeping the existing REST API unchanged.
