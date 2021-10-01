// Créer une connexion WebSocket
const socket = new WebSocket('ws://192.168.65.230:168');


// Écouter les messages
socket.addEventListener('message', function (event) {
  //console.log('Voici un message du serveur', event.data);
  
  /*Si le server m'anonce que l'enregistrement est ok alors je vais afficher le formulaire de connexion*/
  if(event.data.includes("register.ok")){
    document.querySelector('.inscription').style.display='none';
    document.querySelector('.login').style.display='block';

  /*Si le server m'anonce que la connexion est ok alors je cache tout et j'affiche la boite de discusion*/
  } else if(event.data.includes("login.ok") ){  

    /*Comme le login est correct, je vais attribuez la valeur de usernameConnexion pour la réutilisez*/
    UserCorrect = document.getElementById("usernameConnexion").value;

    document.querySelector('.inscription').style.display='none';
    document.querySelector('.login').style.display='none';
    document.querySelector(".MessageBox").style.display='flex';

    window. setInterval(function(){ 
      getText(UserCorrect);
    }, 3000);

  }

  else if(event.data.includes("login.error"))
  {
    alert('Impossible de vous connecter avec ces identifiants');
  }

  if(!event.data.includes("login.ok") && !event.data.includes("register.ok") && !event.data.includes("sendMsg.ok")){

    var Chat = document.getElementById('Message');

    var MessageListe = document.createElement('li');
    MessageListe.textContent = event.data;
    Chat.appendChild(MessageListe);
    window.scrollTo(0, document.body.scrollHeight);

  }
  
});