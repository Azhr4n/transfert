
function addToDo() {
	var ret = prompt("New 'to do element'");
	if (ret.length > 0)
	{
		static_id++;
		var list = document.getElementById('ft_list');
		var div = document.createElement('div');
		var child = document.createTextNode(ret);
		div.appendChild(child);
		div.setAttribute('onclick', 'deleteToDo(this)');
		list.insertBefore(div, list.firstChild);
		setCookie('todolist', list.innerHTML, 1);
	}
}

function deleteToDo(id) {
	alert(id);
	if (confirm('Want to delete this ?')) {
		var list = document.getElementById('ft_list');
		list.removeChild(id);
		setCookie('todolist', list.innerHTML, 1);
	}
}

function setCookie(cname, cvalue, exdays) {
	var d = new Date();
	d.setTime(d.getTime() + (exdays*24*60*60*1000));
	var expires = "expires="+ d.toUTCString();
	document.cookie = cname + "=" + cvalue + ";" + expires + ";path=/";
}

function getCookie(cname) {
	var name = cname + "=";
	var ca = document.cookie.split(';');
	for(var i = 0; i <ca.length; i++) {
		var c = ca[i];
		while (c.charAt(0)==' ') {
			c = c.substring(1);
		}
		if (c.indexOf(name) == 0) {
			return c.substring(name.length,c.length);
		}
	}
	return "";
}

function refresh() {
	var list = document.getElementById('ft_list');
	list.innerHTML = getCookie('todolist');
}
