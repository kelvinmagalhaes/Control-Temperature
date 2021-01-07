function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled"};
	this.sidHashMap["untitled"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Analog Input"] = {sid: "untitled:8"};
	this.sidHashMap["untitled:8"] = {rtwname: "<Root>/Analog Input"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "untitled:12"};
	this.sidHashMap["untitled:12"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/PWM"] = {sid: "untitled:10"};
	this.sidHashMap["untitled:10"] = {rtwname: "<Root>/PWM"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "untitled:9"};
	this.sidHashMap["untitled:9"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Step"] = {sid: "untitled:11"};
	this.sidHashMap["untitled:11"] = {rtwname: "<Root>/Step"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
