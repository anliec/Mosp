/**
 * Created by xaxetrov on 08/06/16.
 */
var ws = new WebSocket("ws://localhost:8100");
var canvas;
var context;
var image = new Image();

window.onload=function() {
    canvas = document.getElementById("picture");
    context = canvas.getContext("2d");
}

function dispMessage(str) {
    document.getElementById("message").innerHTML = str;
}

ws.onopen = function (event) {
    ws.send('{ "type":"text", "content":"Browser ready."}' );
};

ws.onmessage=function(event) {
    var message = JSON.parse(event.data);
    switch(message.type) {
        case "text":
            dispMessage(message.content);
            break;
        case "image":
            var iname = message.path;
            dispMessage("Received " + iname);
            image.src= iname
            image.onload = function () { context.drawImage(image, 0, 0); }
            break;
    }
};

function helloServer()
{
    setTimeout(function() {
        ws.send('{ "type": "image", "content":"Send me a picture"}');
    }, 50);
}