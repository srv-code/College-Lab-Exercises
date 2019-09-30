/* Module: Function Module 1 */

console.log('Loaded at %d: \'%s\'', new Date().getTime(), 'Function Module 1');

function timeLocaleString(txt) {
	txt.value = new Date().toLocaleTimeString();
}

function validateDate(date) {
	var patt = /^(0[1-9]|[12][1-9]|3[01])[/-](0[1-9]|1[0-2])[/-](19\d{2}|2[01][0-9])$/;
	// var patt = /^[0-9]\d$/;
	// console.log('validateDate(): date=%s, test=%s', date, patt, patt.test(date));
	return patt.test(date);
}

function dateCheck() {
	return new Date().toGMTString();
}

/* emulation as facing some issues while setting document.cookie */ 
var cookie = 'dghd=sdhjs;hsdfgs=dsh;uaer=jsd;expires=sdjhjskd;';

function greetUser() {
	var username = getUserName();
	if(username == null) {
		while(username == null || username == '') {
			username = prompt('Enter your username', '');			
			if(username != null) {
				username = username.trim().replace(/[;=]/g, '_');
			}
		}
		setCookie(username, 30);
	} else {
		alert('Welcome again ' + username + '!');
	}
}

function setCookie(username, expDays) {
	console.log('setting username (%s)', username);
	expDate = new Date();
	expDate.setTime(expDate.getTime() + (expDays*24*60*60*1000));
	var newCookieLine = 'user=' + username + '; expires=' + expDate.toGMTString() + ';';
	cookie += newCookieLine;
	console.log('newCookieLine: "%s", cookie: "%s"', newCookieLine, cookie);
}

function getUserName() {
    console.log('document.cookie="%s"', document.cookie);
	console.log('fetching username...');
	var lines = cookie.split(';');
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

function testForEach() {
	var tgt = 'bbc';
	/*
	['aa', 'bb', 'cc'];.forEach(
		function(item) {
			if(item == tgt) {
				console.log('found');
				return;
			}
		}
	);
	console.log('not found');
	*/
	
	var arr = ['aa', 'bb', 'cc'];
	for(var i=0; i<arr.length; i++) {
		if(arr[i] == tgt) {
			console.log('found');
			return true;
		}
	}
	console.log('not found');
	return false;
}

function clearCookie() {
	// document.cookie = '';
	cookie = '';
}

function showCookie() {
	// console.log('cookie: "%s"', document.cookie);
	console.log('cookie: "%s"', cookie);
}

function replaceTest() {
	str = 'abc;def;;ghi';
	console.log('before: "%s"', str);
	str = str.replace(/;/g, '_');
	console.log('after:  "%s"', str);
}

function regexTest1(str) {
	console.log('str="%s', str);
    return /^[a-zA-Z]+$/.test(str);
}

function regexTest2(str) {
	console.log('str=%s', str);
	// return /^[A-Z][a-z]{,8}$/.test(str);
	// return /^[\w\-\$]+@manipal\.(edu|org)$/.test(str);
	return /^((19|20)\d{2})[/-](0[1-9]|1[0-2])[/-](0[1-9]|[12][0-9]|3[01])$/.test(str);
}

function isInRange(tgt, upperLimit, lowerLimit, errmsg, indicator) {
	var regex = '^\\d{'+ lowerLimit +','+ upperLimit +'}$';
    var regexp = new RegExp(regex, 'g');
    var isValid = regexp.test(tgt.value);
	console.log('regex=%s, test=%s', regex, isValid);
	// isValid = tgt.value !== null && new RegExp('\d+{'+lowerLimit+','+upperLimit+'}', 'i').test(tgt.value.trim());
	// showErrMsgAndFocus(isValid, tgt, errmsg, indicator);
	return isValid;
}