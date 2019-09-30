function areInputsValid0(form) {
	with (form) {
		return	isAlpha(name.value) &&
				isNum(age.value) && isInRange(age.value, 18, 60) &&
				isNum(ccard.value) && isInRange(ccard.value.length, 16, 16);
	}
}

function isValidForm(form) {
	with(form) {
		isValid = true;

		if(isAlpha(name.value))
			nameError.innerText = '';
		else {
			name.focus();
			nameError.innerText = 'Invalid name';
			isValid = false;
		}
		console.log('checked name');

		if(isNum(age.value) && isInRange(age.value, 18, 60))
			ageError.innerText = '';
		else {
			age.focus();
			ageError.innerText = 'Invalid age';
			isValid = false;
		}
		console.log('checked age');

		if(isNum(ccard.value) && isInRange(ccard.value.length, 16, 16))
			ccard.innerText = '';
		else {
			ccard.focus();
			ccardError.innerText = 'Invalid credit card number';
			isValid = false;
		}
		console.log('checked ccard');
	}
	return isValid;
}

function areInputsValid(form) { // for test
	var isValid = areInputsValid0(form);
	console.log('isValid=%s\n-----', isValid);
	return isValid;
}

function isAlpha(txt) {
	var isAlpha = /^[a-zA-Z]+$/.test(txt);
	console.log('isAlpha=', isAlpha);
	return isAlpha;
}

function isNum(txt) {
	var isNum = /^\d+$/.test(txt);
	console.log('isNum=', isNum);
	return isNum;
}

function isInRange(val, low, high) {
	var isInRange = val>=low && val<=high;
	console.log('isInRange=', isInRange);
	return isInRange;
}