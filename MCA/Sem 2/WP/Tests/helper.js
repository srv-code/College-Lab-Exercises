console.log('script loaded');

window.onload = function() {
	document.getElementById('div_main').onclick = function(mevent) {
		// console.log('clicked at (client: %d,%d)', mevent.clientX, mevent.clientY);
		// console.log('clicked at (page:   %d,%d)', mevent.pageX, mevent.pageY);
		// console.log('clicked at (offset: %d,%d)', mevent.offsetX, mevent.offsetY);		
		// console.log('clicked at (screen: %d,%d)', mevent.screenX, mevent.screenY);
		
		console.log('clicked at (client: {%d,%d}; page: {%d,%d}; offset: {%d,%d}; screen: {%d,%d};)', 
				mevent.clientX, mevent.clientY,
				mevent.pageX, mevent.pageY,
				mevent.offsetX, mevent.offsetY,
				mevent.screenX, mevent.screenY);
	};
};