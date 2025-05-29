function addItemToCart(name, quantity = 0) {
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
    newCookie = '"' + name + '"=' + quantity;
    document.cookie = newCookie;
    location.reload();
    return document.cookie;
}