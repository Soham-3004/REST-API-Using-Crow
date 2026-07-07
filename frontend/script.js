console.log("Script Started!");
fetch("http://localhost:18080/users").then(response => {console.log(response);});