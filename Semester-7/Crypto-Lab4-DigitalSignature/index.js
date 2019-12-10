const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const nodeRSA = require('node-rsa');
const fs = require('fs');
const app = express();

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
    const plainText = req.body.plainText;

    const key = new nodeRSA({b: 2048});

    const encrypted = key.encrypt(plainText, 'base64');
    console.log(encrypted);

    res.send(encrypted);
});

app.post('checkPublicKey', (req, res) => {

});

app.listen(port, () => {
    console.log(`Listening on port ${port}!`);
});