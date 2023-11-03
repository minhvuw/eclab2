function verify_password() {
    const password1 = document.getElementById("password1").value;
    const password2 = document.getElementById("password2").value;

    if (password1 !== password2) {
        alert("Passwords do not match");
    }
    else if (password1.length < 8) {
        alert("Password is less than 8 characters");
    }
    else {
        alert("The passwords match");
    }
}