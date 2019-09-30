/* Module: Dispatcher Module 1 */

window.onload = function() {
	console.log('Loaded at %d: \'%s\'', new Date().getTime(), 'Dispatcher Module 1');
	console.log('[initialising...]');
	buildList(document.getElementById('listOptions'));
	console.log('[initialisation was successful]');
	document.getElementById('btnSubmit').focus();
}

function clearTextBoxes() {
	document.getElementById('txtOutput').value = '';
    document.getElementById('txtInput').value = '';
	document.getElementById('btnSubmit').focus();
}

function buildList(list) {
	console.log('starting to add <option> to <select> (%o)...', list);
	
	/* Abort if already <select> built */
	if(list.length > 0) {
		console.log('<select> already built, aborting...');
		return;
	}
	
	commands.forEach(function(item, idx) {
		var opt = document.createElement('option');
		opt.text = item;
		opt.value = 'opt' + idx;
		opt.ondblclick = execCmd;
		list.add(opt);
		console.log('added <option> (%o) to <select>', opt);
	});
	console.log('<select> built');
	list.selectedIndex = "0";
	console.log('selected <select>\'s 1st <option>');
}

const newCommand = 'regex-isInRange';
const commands = [	newCommand, 
					'greet-user', 'call', 
					'validate-date', 'regex-test#1', 'regex-test#2',
					'show-cookie', 'clear-cookie', 'time-locale-string', 'test-forEach' ];

function execCmd() {
    var txtOutput = document.getElementById('txtOutput');
    var txtInput = document.getElementById('txtInput');
	// console.log('test: selected item text=%s', commands[document.getElementById('listOptions').selectedIndex]);
	var selectedCmd = commands[document.getElementById('listOptions').selectedIndex];
	console.log('[called command "%s"]', selectedCmd);
	var opSucc = true;

    switch(selectedCmd) {
		case newCommand: // 'regex-isInRange'
			// isInRange(tgt, upperLimit, lowerLimit, errmsg, indicator) {
			txtOutput.value = 'Match result: ' + isInRange(txtInput, 5, 5, null, null);
			break;

		case 'regex-test#1':
			txtOutput.value = 'Match result: ' + regexTest1(txtInput.value);
			break;

			
		case 'regex-test#2':
			txtOutput.value = 'Match result: ' + regexTest2(txtInput.value);
			break;
		
        case 'call':
            txtOutput.value = 'hi';
			break;
			
		case 'time-locale-string':
			timeLocaleString(txtOutput);
			break;
			
		case 'replace-test':
			replaceTest();
			break;
		
		case 'show-cookie':
			showCookie();
			break;
		
		case 'clear-cookie':
			clearCookie();
			break;
			
		case 'test-forEach':
			testForEach();
			break;
			
		case 'greet-user':
			greetUser();
			break;
		
		case 'validate-date':
			txtOutput.value = 'validateDate(): date='+ txtInput.value +', result='+ validateDate(txtInput.value);
			break;
			
		default:
			console.error('Fatal err: Undefined command selected="%s"', selectedCmd);
            alert('Err: Undefined command ('+ selectedCmd +')!');
			opSucc = false;
    }
	console.log('[command "%s" was %s]', selectedCmd, opSucc ? 'successful' : 'failure!');
}