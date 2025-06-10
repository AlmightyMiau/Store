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
        // document.getElementById("editProduct").style.display = "none";
        document.getElementById("deleteProduct").style.display = "none";
    } else {
        document.getElementById("createProductForm").style.display = "none";
        // document.getElementById("editProduct").style.display = "list-item";
        document.getElementById("deleteProduct").style.display = "list-item";
    }
}
function EditProducts() {

}
function DeleteProducts() {
    buttons = document.getElementsByClassName("productDeleteBtn");
    if (document.getElementById("deleteProductHelper").style.display == "none") {
        document.getElementById("deleteProductHelper").style.display = "block";
        document.getElementById("createProduct").style.display = "none";
        // document.getElementById("editProduct").style.display = "none";
        for (let i = 0; i < buttons.length; i++) {
            buttons.item(i).style.display = "block";
        }
    } else {
        document.getElementById("deleteProductHelper").style.display = "none";
        document.getElementById("createProduct").style.display = "list-item";
        // document.getElementById("editProduct").style.display = "list-item";
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

}
function EditUser() {

}
function DeleteUser() {

}