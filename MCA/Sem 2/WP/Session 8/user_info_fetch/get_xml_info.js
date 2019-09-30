console.log('Script loaded at %o', new Date());

function clearForm() {
	with(document.forms['formInfoFetch']) {
		txtTitle.value = resultTitle.innerText = titleInfo.innerText = artistInfo.innerText = albumInfo.innerText = yearInfo.innerText = '';
	}
}

window.onload = function() {
	clearForm();
	document.forms['formInfoFetch'].txtTitle.focus();
};

function fetchInfo() {
	with(document.forms['formInfoFetch']) {
		var inputTitle = txtTitle.value;
		if(inputTitle === null || inputTitle.trim() === '') {
			console.log('no input!');
			return;
		}

		var xmlReq;
		if(window.XMLHttpRequest) { // for IE7+, Chrome, Firefox
			xmlReq = new XMLHttpRequest();
		} else { // for IE5 & 6
			xmlReq = new ActiveXObject('Microsoft.XMLHTTP');
		}

		xmlReq.open('GET', 'cd_details.xml', false);
		xmlReq.send();

		var xmlDoc = xmlReq.responseXML;
		if(xmlDoc == null) {
			resultTitle.innerText = 'XML not found!';
			return;
		}

		var cdTags = xmlDoc.getElementsByTagName('cd');
		for(var i=0; i<cdTags.length; i++) {
			var title = cdTags[i].getElementsByTagName('title')[0].childNodes[0].nodeValue; 
			console.log('title fetched: %s', title);
			if(title === inputTitle) {
				console.log('match found');
				resultTitle.innerText = 'Record found';
				titleInfo.innerText  = inputTitle;
				artistInfo.innerText = cdTags[i].getElementsByTagName('artist')[0].childNodes[0].nodeValue;
				albumInfo.innerText  = cdTags[i].getElementsByTagName('album')[0].childNodes[0].nodeValue;
				yearInfo.innerText   = cdTags[i].getElementsByTagName('year')[0].childNodes[0].nodeValue;
				return;
			}
		}

		clearForm();
		resultTitle.innerText = 'Record not found!';
	}
}