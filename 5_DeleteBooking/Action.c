Action()
{

	lr_start_transaction("Full_transaction_DeleteBoking");

	lr_start_transaction("1_transaction_ToWebTours");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("search", 
		"URL=https://www.google.com/complete/search?client=firefox&channel=ftr&q=", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=text/javascript", 
		"Referer=", 
		"Snapshot=t1.inf", 
		LAST);

	web_add_cookie("MSO=SID&1731426096&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=firstName&Jojo&address2&&username&jojo&hash&47&lastName&Bean%0A&address1&&creditCard&123&expDate&09.09%0A; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='SID&1731428649&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10' Name ='MSO' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=MSO",
		"RegExp=MSO=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/welcome.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='140253.434507898HcVtcizpADHftDcifpHVzccf' Name ='userSession' Type ='ResponseBased'*/
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


//Проверка на загрузку формы логина
	web_reg_find("Text=Welcome to the Web Tours site", LAST);
	
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO={MSO}; DOMAIN=localhost");

	lr_end_transaction("1_transaction_ToWebTours",LR_AUTO);

	lr_start_transaction("2_transaction_Login");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(14);
	
	//Проверка на успешную авторизацию
	web_reg_find("Text=Using the menu to the left", LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t3.inf",
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

	lr_think_time(24);

	lr_start_transaction("3_transaction_To_Itinerary");

/*Correlation comment - Do not change!  Original value='45556-7-JB' Name ='flightID' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4557785-1554-JB' Name ='flightID_1' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_1",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-2327-JB' Name ='flightID_2' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_2",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-3096-JB' Name ='flightID_3' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_3",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-38-JB' Name ='flightID_4' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_4",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-4634-JB' Name ='flightID_5' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_5",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-5403-JB' Name ='flightID_6' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_6",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-6173-JB' Name ='flightID_7' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_7",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-6942-JB' Name ='flightID_8' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_8",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-7711-JB' Name ='flightID_9' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_9",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-8480-JB' Name ='flightID_10' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_10",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-9250-JB' Name ='flightID_11' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_11",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-10019-JB' Name ='flightID_12' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_12",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-10788-JB' Name ='flightID_13' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_13",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-11557-JB' Name ='flightID_14' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_14",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-12327-JB' Name ='flightID_15' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_15",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-130-JB' Name ='flightID_16' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_16",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-138-JB' Name ='flightID_17' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_17",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-146-JB' Name ='flightID_18' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_18",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-153-JB' Name ='flightID_19' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_19",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-16173-JB' Name ='flightID_20' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_20",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-16942-JB' Name ='flightID_21' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_21",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-176-JB' Name ='flightID_22' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_22",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-184-JB' Name ='flightID_23' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_23",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='45555-192-JB' Name ='flightID_24' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_24",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='4556675-20019-u' Name ='flightID_25' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=flightID_25",
		"TagName=input",
		"Extract=value",
		"Name=flightID",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/itinerary.pl*",
		LAST);

	
	//Проверка на переход страницы flight
	web_reg_find("Text=Itinerary", LAST);
	
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_transaction_To_Itinerary",LR_AUTO);

	lr_start_transaction("4_transaction_Delete_way");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_data("itinerary.pl",
		"Action=http://localhost:1080/cgi-bin/itinerary.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=flightID", "Value={flightID}", ENDITEM,
		"Name=flightID", "Value={flightID_1}", ENDITEM,
		"Name=flightID", "Value={flightID_2}", ENDITEM,
		"Name=flightID", "Value={flightID_3}", ENDITEM,
		"Name=flightID", "Value={flightID_4}", ENDITEM,
		"Name=flightID", "Value={flightID_5}", ENDITEM,
		"Name=flightID", "Value={flightID_6}", ENDITEM,
		"Name=flightID", "Value={flightID_7}", ENDITEM,
		"Name=flightID", "Value={flightID_8}", ENDITEM,
		"Name=flightID", "Value={flightID_9}", ENDITEM,
		"Name=flightID", "Value={flightID_10}", ENDITEM,
		"Name=flightID", "Value={flightID_11}", ENDITEM,
		"Name=flightID", "Value={flightID_12}", ENDITEM,
		"Name=flightID", "Value={flightID_13}", ENDITEM,
		"Name=flightID", "Value={flightID_14}", ENDITEM,
		"Name=flightID", "Value={flightID_15}", ENDITEM,
		"Name=flightID", "Value={flightID_16}", ENDITEM,
		"Name=flightID", "Value={flightID_17}", ENDITEM,
		"Name=flightID", "Value={flightID_18}", ENDITEM,
		"Name=flightID", "Value={flightID_19}", ENDITEM,
		"Name=flightID", "Value={flightID_20}", ENDITEM,
		"Name=flightID", "Value={flightID_21}", ENDITEM,
		"Name=flightID", "Value={flightID_22}", ENDITEM,
		"Name=flightID", "Value={flightID_23}", ENDITEM,
		"Name=flightID", "Value={flightID_24}", ENDITEM,
		"Name=flightID", "Value={flightID_25}", ENDITEM,
		"Name=removeFlights.x", "Value=59", ENDITEM,
		"Name=removeFlights.y", "Value=10", ENDITEM,
		"Name=.cgifields", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=21", ENDITEM,
		"Name=.cgifields", "Value=7", ENDITEM,
		"Name=.cgifields", "Value=26", ENDITEM,
		"Name=.cgifields", "Value=17", ENDITEM,
		"Name=.cgifields", "Value=2", ENDITEM,
		"Name=.cgifields", "Value=22", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		"Name=.cgifields", "Value=18", ENDITEM,
		"Name=.cgifields", "Value=23", ENDITEM,
		"Name=.cgifields", "Value=16", ENDITEM,
		"Name=.cgifields", "Value=13", ENDITEM,
		"Name=.cgifields", "Value=25", ENDITEM,
		"Name=.cgifields", "Value=6", ENDITEM,
		"Name=.cgifields", "Value=3", ENDITEM,
		"Name=.cgifields", "Value=9", ENDITEM,
		"Name=.cgifields", "Value=12", ENDITEM,
		"Name=.cgifields", "Value=20", ENDITEM,
		"Name=.cgifields", "Value=14", ENDITEM,
		"Name=.cgifields", "Value=15", ENDITEM,
		"Name=.cgifields", "Value=8", ENDITEM,
		"Name=.cgifields", "Value=4", ENDITEM,
		"Name=.cgifields", "Value=24", ENDITEM,
		"Name=.cgifields", "Value=19", ENDITEM,
		"Name=.cgifields", "Value=10", ENDITEM,
		"Name=.cgifields", "Value=5", ENDITEM,
		LAST);

	lr_end_transaction("4_transaction_Delete_way",LR_AUTO);

	lr_end_transaction("Full_transaction_DeleteBoking",LR_AUTO);

	return 0;
}