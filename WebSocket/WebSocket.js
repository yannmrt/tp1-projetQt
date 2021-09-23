// Créer une connexion WebSocket
const socket = new WebSocket('ws://192.168.65.230:168');

/*
// La connexion est ouverte
socket.addEventListener('open', function (event) {
 socket.send('truc');
});
*/
// Écouter les messages
socket.addEventListener('message', function (event) {
  console.log('Voici un message du serveur', event.data);
  if(event.data = "login.ok"){
    document.getElementById('FormulaireInscription').style.display='none';
    document.getElementById('FormulaireConnexion').style.display='none';
    document.getElementById('textBox').style.display='flex';
    var UserCorrect = document.getElementById("usernameInscription").value;
  }
});


