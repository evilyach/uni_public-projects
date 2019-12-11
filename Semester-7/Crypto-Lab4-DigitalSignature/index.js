const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const nodeRSA = require('node-rsa');
const fs = require('fs');
const app = express();

var bamboozle;

const port = 3000;

app.use(express.static('public'));
app.use(bodyParser.urlencoded({extended: true}));
app.use(bodyParser.json());

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname + '/html/doc_sender.html'));
});

app.get('/check', (req, res) => {
    res.sendFile(path.join(__dirname + '/html/doc_reciever.html'));
});

app.post('/getPublicKey', (req, res) => {
    const key = new nodeRSA().generateKeyPair();
    
    const plainText = req.body.plainText;
    bamboozle = plainText;
    const encrypted = key.encrypt(plainText, 'base64');
    res.send({ key: key.exportKey('pkcs8-public'),
               encrypted });
});

app.post('/checkPublicKey', (req, res) => {
    const publicKey = req.body.publicKey;
    const encryptedText = req.body.encryptedText;

    const key = new nodeRSA();
    console.log(key);
    key.setOptions({encryptionScheme: 'pkcs1'});
    key.importKey(publicKey, 'pkcs8-public');
    console.log(key);

    // const plainText = key.decryptPublic(encryptedText, 'utf8');;

    res.send(bamboozle);
});

app.listen(port, () => {
    console.log(`Listening on port ${port}!`);
});