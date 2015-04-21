// when a java program prints this file, 
// pictures[] will contain local files desired to put in slideshow
// add better scrolling effect later;

var pictures = [
"http://cdn.damninteresting.com/wp-content/uploads/2005/12/one.gif",
"http://www.clker.com/cliparts/G/V/k/w/7/Z/two-green-square-rounded-edge-md.png",
"http://rayhigdon.com/wp-content/uploads/2014/05/daily-routine-tips.gif",
];

var i= -1;

document.addEventListener('keydown', function(event) {
//uncomment to prevent backspace from navigating page back in browser
//(also prevents scrolling with arrow keys)
//event.preventDefault();
        
    //right key or enter key
    if(event.keyCode == 39 || event.keyCode == 13) {
        i++;
        if(i <= pictures.length-1){
            document.images.slide.src = pictures[i];
        }
        else{
            document.images.slide.src = pictures[0];
            i=0;
        }
    }
    //left key or backspace
    else if(event.keyCode == 37 || event.keyCode == 8) {
        i--;
        if(i >= 0){
            document.images.slide.src= pictures[i];
        }
        else if (i<0){
            document.images.slide.src = pictures[pictures.length-1];
            i=pictures.length-1;
        }
    }
    //esc key pressed: reset
    else if(event.keyCode == 27){
        document.images.slide.src=pictures[0];
        i=0;
    }
    return;
});
