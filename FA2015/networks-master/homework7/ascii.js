"use strict";
var playing = false;
document.getElementById("stage").value = ANIMATIONS["EXERCISE"];
var anim = document.getElementById("animation").value;
var animArray = ANIMATIONS[anim].split("=====\n");
var index = 0;
var player;
fontSizeChange();
var interval = 250;

function switchAnimation(){
    index = 0;
    anim = document.getElementById("animation").value;
    document.getElementById("stage").value = ANIMATIONS[anim];
    animArray = ANIMATIONS[anim].split("=====\n");
}

function togglePlay(){
    if(!playing){
        playing = true;
        document.getElementById("Start").disabled=true;
        document.getElementById("Stop").disabled=false;
        startPlay();
    }
    else{
        playing = false;
        document.getElementById("Start").disabled=false;
        document.getElementById("Stop").disabled=true;
        stopPlay();
        document.getElementById("stage").value=ANIMATIONS[anim];
    }
}

function startPlay(){
    player = setInterval(play, interval);
}

function stopPlay(){
    index = 0;
    clearInterval(player);
}

function play(){
    document.getElementById("stage").value = animArray[index];
    if(index < animArray.length-1){
        index++;
    }
    else{
        index = 0;
    }
}

function fontSizeChange(){
    var size = document.getElementById("fontsize").value;
    if (size=="Tiny"){
        document.getElementById("stage").style.fontSize="7pt";
    }
    else if(size=="Small"){
        document.getElementById("stage").style.fontSize="10pt";
    }
    else if(size=="Medium"){
        document.getElementById("stage").style.fontSize="12pt";
    }
    else if(size=="Large"){
        document.getElementById("stage").style.fontSize="16pt";
    }
    else if(size=="ExtraLarge"){
        document.getElementById("stage").style.fontSize="24pt";
    }
    else if(size=="XXL"){
        document.getElementById("stage").style.fontSize="32pt";
    }
}

function speedChange(){
    console.log("changed speed");
    interval=document.querySelector('input[name="speed"]:checked').value;
    if (playing){
        clearInterval(player);
        startPlay();
    }
}