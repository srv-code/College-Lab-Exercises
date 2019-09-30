SCRIPT_VERSION=1.2;
console.log('validate_form.js (v%f) loaded at %o', SCRIPT_VERSION, new Date());

window.onload = setInitialFocus;

function setInitialFocus() {
	document.forms['formRegistration']['txtName'].focus();
}

function clearForm() {
	with(document.forms['formRegistration']) {
		txtName.value = txtName.className = nameErrorMsg.innerText = nameErrorMsg.className = ''; 
			nameValidIndicator.style.visibility = 'hidden';
	/*
		txtAddress.value = txtAddress.className = addressErrorMsg.innerText = addressErrorMsg.className = ''; 
			addressValidIndicator.style.visibility = 'hidden';
		
		txtZipCode.value = txtZipCode.className = zipcodeErrorMsg.innerText = zipcodeErrorMsg.className = ''; 
			zipcodeValidIndicator.style.visibility = 'hidden';
		
		countryErrorMsg.innerText = countryErrorMsg.className = ''; 
			countryValidIndicator.style.visibility = 'hidden';
	*/
		genderErrorMsg.innerText = genderErrorMsg.className = ''; 
			genderValidIndicator.style.visibility = 'hidden';

		tncErrorMsg.innerText = tncErrorMsg.className = ''; 
			tncValidIndicator.style.visibility = 'hidden';

		txtEmail.value = txtEmail.className = emailErrorMsg.innerText = emailErrorMsg.className = ''; 
			emailValidIndicator.style.visibility = 'hidden';

		txtPhoneNo.value = txtPhoneNo.className = phonenoErrorMsg.innerText = phonenoErrorMsg.className = ''; 
			phonenoIndicator.style.visibility = 'hidden';

		txtPwd.value = txtPwd.className = pwdErrorMsg.innerText = pwdErrorMsg.className = ''; 
			pwdValidIndicator.style.visibility = 'hidden';

		txtVerifyPwd.value = txtVerifyPwd.className = verifyPwdErrorMsg.innerText = verifyPwdErrorMsg.className = ''; 
			verifyPwdValidIndicator.style.visibility = 'hidden';
		
		txtVerifyPwd.value = txtVerifyPwd.className = verifyPwdErrorMsg.innerText = verifyPwdErrorMsg.className = ''; 
			verifyPwdValidIndicator.style.visibility = 'hidden';
	}

	setInitialFocus();
}

/* Returns boolean */
function validateInputFields(form) {
	with(form) {
		if(	isAlphabetic(txtName, nameErrorMsg, 'Only alphabets and spaces!', nameValidIndicator)
		// return	isAlphabetic(txtName, nameErrorMsg, 'Only alphabets and spaces!', nameValidIndicator)
			// &&	isAlphaNumeric(txtAddress, addressErrorMsg, 'Only alphanumerics & spaces!', addressValidIndicator)
			// &&	isNumeric(txtZipCode, zipcodeErrorMsg, 'Only numeric value!', zipcodeValidIndicator)
			// &&	isInRange(txtZipCode, 5, 5, zipcodeErrorMsg, 'Strictly 5 digits!', zipcodeValidIndicator)
			// &&	isSelected(dropdownCountry, countryErrorMsg, 'Required!', countryValidIndicator)
			&&	isChecked('gender', genderErrorMsg, 'Required!', genderValidIndicator)			
			&&	isValidEmail(txtEmail, emailErrorMsg, 'Invalid format!', emailValidIndicator)
			&&	isNumeric(txtPhoneNo, phonenoErrorMsg, 'Only numeric value!', phonenoIndicator)
			&&	isInRange(txtPhoneNo, 10, 10, phonenoErrorMsg, 'Strictly 10 digits!', phonenoIndicator)
			&&	isValidPassword(txtPwd, pwdErrorMsg, '8-15 characters', pwdValidIndicator)
			&&	areSame(txtVerifyPwd, txtPwd, verifyPwdErrorMsg, 'Didn\'t match!', verifyPwdValidIndicator)
			&&	isChecked('tnc', tncErrorMsg, 'Please check T&C!', tncValidIndicator))
			
			alert('Congrats ' + txtName.value + '!\nYou successfully subscribed to our Newsletter!');
	}
}

function isValidPassword(tgt, errmsgElm, errmsg, indicatorElm) {
	// Of length 5-10 and only alphabets or numbers or @ or $ or _
	var isValid = /^[\w@$_]{8,15}$/.test(tgt.value);
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function areSame(tgt, ref, errmsgElm, errmsg, indicatorElm) {
	var isValid = tgt.value === ref.value;
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isValidEmail(tgt, errmsgElm, errmsg, indicatorElm) {	
	isValid = /^([\-\$]*\w+[\-\$]*)*@dca\.ac\.in$/.test(tgt.value);
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isChecked(name, errmsgElm, errmsg, indicatorElm) {
	var isValid = false;
	var checkboxes = document.getElementsByName(name);
	// console.log('checking for %s ...', name);
	// console.log('  checkboxes: %o', checkboxes);
	for(var i=0; i<checkboxes.length; i++) {
		// console.log('  inspecting cbx: %o, checked?=%s', checkboxes[i], checkboxes[i].checked);
		if(checkboxes[i].checked) {
			isValid = true;
			break;
		}
	}
	// console.log('sending to showErrMsgAndFocus(isValid=%s, null, errmsgElm=%o, errmsg=%s, indicatorElm=%o) ...', isValid, errmsgElm, errmsg, indicatorElm);
	showErrMsgAndFocus(isValid, null, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isSelected(tgt, errmsgElm, errmsg, indicatorElm) {
	var isValid = tgt.value !== 'Select';
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isInRange(tgt, upperLimit, lowerLimit, errmsgElm, errmsg, indicatorElm) {
	// console.log('regex=%s, tgt.value=%s', regex, tgt.value);
	isValid = new RegExp('^\\w{'+ lowerLimit +','+ upperLimit +'}$', 'g').test(tgt.value);
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isAlphaNumeric(tgt, errmsgElm, errmsg, indicatorElm) {
	var isValid = /^[0-9a-zA-Z ]+$/.test(tgt.value);
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isNumeric(tgt, errmsgElm, errmsg, indicatorElm) {
	// console.log('isNumeric(tgt=%o, errmsgElm=%o, errmsg=%o, indicatorElm=%o) called', tgt, errmsgElm, errmsg, indicatorElm);
	var isValid = /^\d+$/.test(tgt.value);
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

function isAlphabetic(tgt, errmsgElm, errmsg, indicatorElm) {
	var isValid = /^[a-zA-Z]+$/.test(tgt.value.trim());
	showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm);
	return isValid;
}

/* Sets or resets error message */
function showErrMsgAndFocus(isValid, tgt, errmsgElm, errmsg, indicatorElm) {
	if(isValid) { // clears err element
		if(tgt != null && tgt != undefined)
			tgt.className = '';

		if(errmsgElm != null && errmsgElm != undefined) {
				errmsgElm.innerText = '';
				errmsgElm.className = '';
		}

		if(indicatorElm != null && indicatorElm != undefined)
			indicatorElm.src = 'img/tick.jpg';

	} else { // sets error message
		if(tgt != null && tgt != undefined) {
			tgt.focus();
			tgt.className = 'error';
		}

		if((errmsgElm != null && errmsgElm != undefined) 
			&& (errmsg != null && errmsg != undefined)) {
			errmsgElm.innerText = errmsg;
			errmsgElm.className = 'errormsg';
		}

		if(indicatorElm != null && indicatorElm != undefined)
			indicatorElm.src = 'img/cross.jpg';
	}

	if(indicatorElm != null && indicatorElm != undefined)
		indicatorElm.style.visibility = 'visible';
}