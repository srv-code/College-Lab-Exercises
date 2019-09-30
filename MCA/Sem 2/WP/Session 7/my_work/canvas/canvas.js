var canvas, context, txtCoords, canvasUnsupported;
var currX, currY, prevX, prevY;
var colors = [ '#ff0000', '#00ff00', '#0000ff' ]; /* RGB only */
var colorIdx = 0;

window.onload = function() {
	canvas = document.getElementById('main_canvas');
	context = canvas.getContext('2d');
	txtCoords = document.getElementById('txt_coords');
	canvasUnsupported = context == null;
	
	if(canvasUnsupported) {
		txtCoords.className = 'display_panel';
		txtCoords.value = 'Your browser does not support canvas drawing!';
		return;
	}
	
	// console.log('init: curr coord: (%d,%d), prev coord: (%d,%d)', currX, currY, prevX, prevY);
}

function sketch(mouseEvent) {
	if(canvasUnsupported)
		return;
	
	currX = mouseEvent.offsetX;
	currY = mouseEvent.offsetY;
	
	context.beginPath();
	context.strokeStyle = colors[ colorIdx++ % colors.length ];
	context.moveTo(prevX, prevY);
	context.lineTo(currX, currY);
	context.stroke();
	context.fill();
	context.closePath();
	
	prevX = currX;
	prevY = currY;
	
	txtCoords.className = 'display_panel';
	txtCoords.value = 'Coordinates: ('+ prevX +', '+ prevY +')';
	
	// console.log('sketch: curr coord: (%d,%d), prev coord: (%d,%d), color=%s', currX, currY, prevX, prevY, context.strokeStyle);
}

function clearCoordDisplay() {
	if(canvasUnsupported)
		return;
	
	txtCoords.className = 'invisible';
}