// Créer une connexion WebSocket
const socket = new WebSocket('ws://192.168.65.230:168');


// Écouter les messages
socket.addEventListener('message', function (event) {
  console.log('Voici un message du serveur', event.data);
  
  if(event.data === "register.ok"){
    document.querySelector('.inscription').style.display='none';
    document.querySelector('.login').style.display='block';

  }

  if(event.data === "login.ok"){  
    document.querySelector('.inscription').style.display='none';
    document.querySelector('.login').style.display='none';
    document.querySelector(".MessageBox").style.display='flex';
    UserCorrect = document.getElementById("usernameConnexion").value;
  }

  
  

  
});


