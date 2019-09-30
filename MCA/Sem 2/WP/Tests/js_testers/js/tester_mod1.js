window.onload = function() {
    document.getElementById('txtMsg').value="Loaded: tester_mod1.js at " + (new Date().getTime());
    document.getElementById('txtCmd').focus();
}

function execCmd() {
    var txtOutput = document.getElementById('txtOutput');
    var txtInput = document.getElementById('txtInput');

    switch(document.getElementById('txtCmd').value) {
        case 'call':
            alert('hi');
            break;
			
		case 'add-select':  // will require a <select> element
			console.log('starting to build select options...');
			var list = document.getElementById('listDemo');
			console.log('captured <select>: %o', list);
			
			/* Abort if already <select> built */
			if(list.length > 0) {
				console.log('list already built, aborting...');
				return;
			}
			
			var options = ['aa', 'bb', 'cc'];
			options.forEach(function(item, idx) {
				var opt = document.createElement('option');
				opt.text = item;
				opt.value = 'opt' + idx;
				list.add(opt);
				console.log('added <option> (%o) to <select>', opt);
			});
			console.log('Building <select> done');
			list.selectedIndex = "0";
			console.log('Selected <select>\'s 1st <option>');
			break;
			
		case 'array-foreach':
			var arr = [ 'aa', 'bb', 'cc' ];
			txtOutput.value = 'array items:';
			arr.forEach(function(item) {
				txtOutput.value += '\n  ' + item;
			});
			break;

        case 'cookie_len': // shows cookie length
            txtOutput.value = document.cookie.length;
            break;

        case 'set_cookie':
            var cookieData = txtInput.value.trim();
            // alert('data: ' + cookieData);
            if(cookieData == '') {
                alert('Err: Blank cookie data!');
                return;
            }
            document.cookie = '';
            document.cookie = cookieData;
            txtOutput.value = '[Cookie data set] \n';
            txtOutput.value += '[Browser cookie: "' + document.cookie + '"] \n';
            txtOutput.value += '[cookieData: "' + cookieData + '"] \n';
            break;

        case 'show_cookie':
            txtOutput.value = "Cookie data: '" +  document.cookie + "'";
            break;

        case 'greet_user':
            if(greetUser(txtOutput))
                txtOutput.value += '\n[Operation was ' + 'successfull]';
            else
                txtOutput.value += '\n[Operation was ' + 'failure]';
            break;


        case 'greet_user2':
            if(greetUser2(txtOutput))
                txtOutput.value += '\n[Operation was ' + 'successfull]';
            else
                txtOutput.value += '\n[Operation was ' + 'failure]';
            break;

        case 'regex-match':
            regexMatchTest();
            break;

        case 'null-test':
            var a = null;
            txtOutput.value = 'a is null? ' + (a === null) + '\n';
            txtOutput.value += 'a.length: ' + a.length + '\n'; // call to a null variable
            txtOutput.value += 'I\'m alive';
            break;

        case 'concat-test':
            var a = 'Sourav';
            var b = 12.59;
            var c = /(\d)+/g;
            var o = {
                    name : 'Priya',
                    age : 21
                };
            var n;
            var x = true;
            var y = false;
            var arr = ['aaa', 'bbb', 225, { name: 'nunu', age: 5 }];

            if(x == y)
                txtOutput.value += '\nboolean test passed!\n';

            txtOutput.value += arr.length;
            txtOutput.value += typeof arr[3].age;
            break;

        default:
            alert('Invalid command!');
            txtCmd.value = '';
            txtCmd.focus();
    }
}

// function regexMatchTest(var txtInput, var txtOutput) {
function regexMatchTest() {
    var splits = txtInput.value.split(';');
    var str  = splits[0];
    var patt = splits[1];
    var flg  = splits[2];

    for(var i=0; i<3; i++) {
        if(splits[i] === null || splits[i] === undefined) {
            txtOutput.value = '[Usage: <string>;<pattern>;<flags>;]';
            return;
        }
    }

    txtOutput.value =  'str    = "' + str + '" \n';
    txtOutput.value += 'patt   = "' + patt + '" \n';
    txtOutput.value += 'flg    = "' + flg + '" \n';
    // var regexp = new RegExp(patt, flg);
    // txtOutput.value += 'result = ' + regexp.match(str) + '\n';
    txtOutput.value += 'result = ' + str.match(/\w+/gi) + '\n';
}

function greetUser() {
    txtOutput.value = '[started]';
    var lines = document.cookie.split(';');
    for(var i=0; i<lines.length; i++) {
        txtOutput.value += '\n[checking cookie line '+ i +': "'+ lines[i] +'"]';
        var attrs = lines[i].split('=');
        if(attrs[0].trim() == 'user') {
            txtOutput.value += '\n[attr "user" found at idx '+i+']';
            var name = attrs[1];
            if(name.trim() == '')
                txtOutput.value += '\n[Err: username is blank!]';
            else {
                txtOutput.value += '\nMessage: Hi ' + name + '!';
                return true;
            }
        }
        txtOutput.value += '\n[rejected line: ' + lines[i] + ']';
    }
    txtOutput.value += '\n[Err: Username attribute missing!]';
    return false;
}

/* version 2 - for interactive output */
function greetUser2() {
    txtOutput.value = '[started]';
    var lines = document.cookie.split(';');
    for(var i=0; i<lines.length; i++) {
        txtOutput.value += '\n[checking cookie line '+ i +': "'+ lines[i] +'"]';
        var attrs = lines[i].split('=');
        if(attrs[0].trim() == 'user') {
            txtOutput.value += '\n[attr "user" found at idx '+i+']';
            var name = attrs[1];
            if(name.trim() == '')
                txtOutput.value += '\n[Err: username is blank!]';
            else {
                // txtOutput.value += '\nMessage: Hi ' + name + '!';
                alert('Welcome back ' + name + '!');
                return true;
            }
        }
        txtOutput.value += '\n[rejected line: ' + lines[i] + ']';
    }
    txtOutput.value += '\n[Err: Username attribute missing!]';
    txtOutput.value += '\n[setting new username from user input]';
    var name = prompt('Enter your name', '<Your name>');
    document.cookie += ';user=' + name + ';';
    txtOutput.value += '\n[username set to ' + name + ']';
    return false;
}