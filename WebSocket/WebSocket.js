/*
var socket = null;
try {
    socket = new WebSocket("ws://192.168.65.230:178");
} catch (exception) {
    console.error(exception);
}

socket.onerror = function (error) {
    console.error(error);
};


socket.onopen = function (event) {
    this.onmessage = function (msg) {
        this.send('MessageChat', msg);
    };
};
*/ 


// Créer une connexion WebSocket
const socket = new WebSocket('ws://192.168.65.230:178');

// La connexion est ouverte
socket.addEventListener('open', function (event) {
 socket.send('Coucou le serveur !');
});

// Écouter les messages
socket.addEventListener('message', function (event) {
  console.log('Voici un message du serveur', event.data);
});
