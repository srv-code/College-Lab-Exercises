console.log('script loaded');

window.onload = greetUser;

function greetUser() {
	var username = getUserName();
	if(username == null) {
		while(username == null || username == '') {
			username = prompt('Enter your username', '');			
			if(username != null) {
				// username = username.trim().replace(/[;=]/g, '_');
				username = username.trim();
			}
		}
		setInCookie(username, 30);
	} else {
		alert('Welcome again ' + username + '!');
	}
}

function getUserName() {
    console.log('document.cookie="%s"', document.cookie);
    console.log('fetching username...');
	var lines = document.cookie.split(';');
	for(var i=0; i<lines.length; i++) {
		console.log('inspecting cookie line "%s" ...', lines[i]);
		var splits = lines[i].split('=');
		if(splits[0] != null && splits[0] != undefined && splits[0] == "user") {
			console.log('found "user", value="%s"', splits[1]);
			return splits[1];
		}
	}
	console.log('"user" not found!');
	return null;
}

function setInCookie(username, expDays) {
	console.log('setting username (%s)', username);
	expDate = new Date();
	expDate.setTime(expDate.getTime() + (expDays*24*60*60*1000));
	var newCookieLine = 'user=' + username + '; expires=' + expDate.toGMTString() + ';';
	document.cookie += newCookieLine;
	console.log('newCookieLine: "%s", document.cookie: "%s"', newCookieLine, document.cookie);
}