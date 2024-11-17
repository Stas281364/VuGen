Action()
{

	lr_start_transaction("FULL-transaction_CheckListOfWays");

	lr_start_transaction("1_transaction_ToWebTours");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("MSO=SID&1731426031&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	//Проверка на загрузку формы логина
	web_reg_find("Text=Welcome to the Web Tours site", LAST);

/*Correlation comment - Do not change!  Original value='SID&1731426096&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10' Name ='MSO' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=MSO",
		"RegExp=MSO=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/welcome.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='140253.227703524HcVtcHfpttDcifpzfct' Name ='userSession' Type ='ResponseBased'*/
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

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO={MSO}; DOMAIN=localhost");

	lr_end_transaction("1_transaction_ToWebTours",LR_AUTO);

	lr_start_transaction("2_transaction_Login");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(18);
	
	//Проверка на успешную авторизацию
	web_reg_find("Text=Using the menu to the left", LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=0", ENDITEM,
		"Name=login.y", "Value=0", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("2_transaction_Login",LR_AUTO);

	lr_start_transaction("3_transaction_To_Itinerary");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(92);

	//Проверка на переход страницы flight
	web_reg_find("Text=Itinerary", LAST);
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_transaction_To_Itinerary",LR_AUTO);

	lr_end_transaction("FULL-transaction_CheckListOfWays",LR_AUTO);

	return 0;
}