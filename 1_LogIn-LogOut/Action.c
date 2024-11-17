Action()
{

	lr_start_transaction("FULL-transaction_LogIn-LogOut");

	lr_start_transaction("1_transaction_LogIn");

	web_add_cookie("MSO=SID&1730702057&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=firstName&Jojo&address2&&username&jojo&hash&47&lastName&Bean%0A&address1&&creditCard&123&expDate&09.09%0A; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	//Проверка на загрузку формы логина
	web_reg_find("Text=Welcome to the Web Tours site", LAST);

/*Correlation comment - Do not change!  Original value='140194.809477521HcVVcHApfVcftDczHpzcDAHf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='SID&1730704923&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10' Name ='MSO' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=MSO",
		"RegExp=MSO=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/welcome.pl*",
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

//Проверка на авторизацию
	web_reg_find("Text=Using the menu to the left", LAST);
	
	web_add_cookie("MSO={MSO}; DOMAIN=localhost");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(8);
	
	

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=63", ENDITEM,
		"Name=login.y", "Value=15", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	
	lr_end_transaction("1_transaction_LogIn",LR_AUTO);

	lr_end_transaction("FULL-transaction_LogIn-LogOut",LR_AUTO);

	return 0;
}