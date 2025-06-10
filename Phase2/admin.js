function ViewProducts() {
    if (document.getElementById("productOptions").style.display == "none") {
        document.getElementById("productOptions").style.display = "block";
        document.getElementById("product-window").style.display = "block";
        document.getElementById("Users").style.display = "none";
    } else {
        document.getElementById("productOptions").style.display = "none";
        document.getElementById("product-window").style.display = "none";
        document.getElementById("Users").style.display = "inline";
    }
}

function CreateProducts() {
    if (document.getElementById("createProductForm").style.display == "none") {
        document.getElementById("createProductForm").style.display = "block";
        document.getElementById("editProduct").style.display = "none";
        document.getElementById("deleteProduct").style.display = "none";
    } else {
        document.getElementById("createProductForm").style.display = "none";
        document.getElementById("editProduct").style.display = "list-item";
        document.getElementById("deleteProduct").style.display = "list-item";
    }
}
function EditProducts() {
    if (document.getElementById("editProductForm").style.display == "none") {
        document.getElementById("editProductForm").style.display = "block";
        document.getElementById("createProduct").style.display = "none";
        document.getElementById("deleteProduct").style.display = "none";
    } else {
        document.getElementById("editProductForm").style.display = "none";
        document.getElementById("createProduct").style.display = "list-item";
        document.getElementById("deleteProduct").style.display = "list-item";
    }
}
function DeleteProducts() {
    buttons = document.getElementsByClassName("productDeleteBtn");
    if (document.getElementById("deleteProductHelper").style.display == "none") {
        document.getElementById("deleteProductHelper").style.display = "block";
        document.getElementById("createProduct").style.display = "none";
        document.getElementById("editProduct").style.display = "none";
        for (let i = 0; i < buttons.length; i++) {
            buttons.item(i).style.display = "block";
        }
    } else {
        document.getElementById("deleteProductHelper").style.display = "none";
        document.getElementById("createProduct").style.display = "list-item";
        document.getElementById("editProduct").style.display = "list-item";
        for (let i = 0; i < buttons.length; i++) {
            buttons.item(i).style.display = "none";
        }
    }
}

function ViewUsers() {
    if (document.getElementById("userOptions").style.display == "none") {
        document.getElementById("userOptions").style.display = "block";
        document.getElementById("user-window").style.display = "block";
        document.getElementById("Products").style.display = "none";
    } else {
        document.getElementById("userOptions").style.display = "none";
        document.getElementById("user-window").style.display = "none";
        document.getElementById("Products").style.display = "inline";
    }
}

function CreateUser() {
    if (document.getElementById("createUserForm").style.display == "none") {
        document.getElementById("createUserForm").style.display = "block";
        document.getElementById("deleteUser").style.display = "none";
    } else {
        document.getElementById("createUserForm").style.display = "none";
        document.getElementById("deleteUser").style.display = "list-item";
    }
}
function EditUser() {

}
function DeleteUser() {
    buttons = document.getElementsByClassName("userDeleteBtn");
    if (document.getElementById("deleteUserHelper").style.display == "none") {
        document.getElementById("deleteUserHelper").style.display = "block";
        document.getElementById("createUser").style.display = "none";
        // document.getElementById("editUser").style.display = "none";
        for (let i = 0; i < buttons.length; i++) {
            buttons.item(i).style.display = "block";
        }
    } else {
        document.getElementById("deleteUserHelper").style.display = "none";
        document.getElementById("createUser").style.display = "list-item";
        // document.getElementById("editUser").style.display = "list-item";
        for (let i = 0; i < buttons.length; i++) {
            buttons.item(i).style.display = "none";
        }
    }
}