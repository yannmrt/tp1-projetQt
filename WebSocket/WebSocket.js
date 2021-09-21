var socket = null;
try {
    socket = new WebSocket("ws://192.168.65.230:178");
} catch (exception) {
    console.error(exception);
}

socket.onerror = function (error) {
    console.error(error);
};

// Lorsque la connexion est �tablie.
socket.onopen = function (event) {
    console.log("Connexion �tablie.");

    // Lorsque la connexion se termine.
    this.onclose = function (event) {
        console.log("Connexion termin�.");
    };

    // Lorsque le serveur envoi un message.
    this.onmessage = function (event) {
        console.log("Message:", event.data);
    };

    // Envoi d'un message vers le serveur.
    this.send("Hello world!");
};

$('#ButtonEnvoyer').click(function () {
    ws.send(document.querySelector('#BoiteMessage').value);
})