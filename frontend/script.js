console.log("Script Started!");

const tableBody = document.getElementById("userTable");

const nameInput = document.getElementById("nameInput");
const roleInput = document.getElementById("roleInput");
const addUserBtn = document.getElementById("addUserBtn");

function fetchUsers(){
    fetch("http://localhost:18080/users")
    .then(response => response.json())
    .then(data => {renderUsers(data)});
}
fetchUsers();

function renderUsers(users){
    tableBody.innerHTML = "";
     for(const user of users){
        createUserRow(user);
     }
}

function createUserRow(user){
        //create table row ele
        const row = document.createElement("tr");
        
        //create table data
        const idCell = document.createElement("td");
        const nameCell = document.createElement("td");
        const roleCell = document.createElement("td");

        //add data
        idCell.textContent = user.id;
        nameCell.textContent = user.name;
        roleCell.textContent = user.role;

        //add the rows with data to table row
        row.appendChild(idCell);
        row.appendChild(nameCell);
        row.appendChild(roleCell);  

        //finally append each table row to the table body 
        tableBody.appendChild(row);      
}

function addUser(user){
    return fetch("http://localhost:18080/users", 
        {method: "POST",
        headers: {"Content-Type": "application/json"},
        body:JSON.stringify(user)
        });
}

function handleAddUser(){
    const name = nameInput.value;
    const role = roleInput.value;
    
    const user = {
        name,
        role
    };
    addUser(user).then(() => {
        fetchUsers();
        nameInput.value = "";
        roleInput.value = "";
    });
}

addUserBtn.addEventListener("click",()=>{handleAddUser()});