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

const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', (socket) => {
  socket.on('MessageChat', (msg) => {
    io.emit('MessageChat', msg);
  });
});

server.listen(3000, () => {
  console.log('Serveur en ligne');
});