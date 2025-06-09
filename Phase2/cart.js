function addItemToCart(name, quantity = 0) {
    name = name.replace(/ /g,"_"); // replace spaces with underscores
    // If cookie is already there AND passed quantity is 0, do ++
    const cookieValue = document.cookie
        .split("; ")
        .find((row) => row.startsWith('"' + name + '"='))
        ?.split("=")[1];
    if (quantity == 0) {
        if (cookieValue > 0) {
            quantity = cookieValue;
        }
        quantity++;
    }
    newCookie = '"' + name + '"=' + quantity;
    document.cookie = newCookie;
    location.reload();
    return document.cookie;
}

function removeItemFromCart(name, quantity = 0) {
    name = name.replace(/ /g,"_"); // replace spaces with underscores
    // If cookie is already there AND passed quantity is 0, do ++
    const cookieValue = document.cookie
        .split("; ")
        .find((row) => row.startsWith('"' + name + '"='))
        ?.split("=")[1];
    if (quantity == 0) {
        if (cookieValue > 0) {
            quantity = cookieValue;
        }
        quantity--;
    }
    expire = "";
    if (quantity == 0) { // 
        expire = '; Max-Age=-99999';
    }
    newCookie = '"' + name + '"=' + quantity + expire;
    document.cookie = newCookie;
    location.reload();
    return document.cookie;
}