Action()
{

	lr_start_transaction("Full_transaction_SearchTicketNoBuy");

	lr_start_transaction("1_transaction_Load_WebTours");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("MSO=SID&1730995090&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=firstName&Jojo&username&jojo&address2&&hash&47&expDate&09.09&creditCard&123&address1&&lastName&Bean%0A; DOMAIN=localhost");

	web_add_header("Priority", 
		"u=0, i");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	//ѕроверка на загрузку формы логина
	web_reg_find("Text=Welcome to the Web Tours site", LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Priority", 
		"u=4");

	web_url("header.html", 
		"URL=http://localhost:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

/*Correlation comment - Do not change!  Original value='SID&1731339654&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10' Name ='MSO' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=MSO",
		"RegExp=MSO=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/welcome.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='140246.225516403HcVDQVfpccftDciDptQVDf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO={MSO}; DOMAIN=localhost");

	lr_end_transaction("1_transaction_Load_WebTours",LR_AUTO);

	lr_start_transaction("2_transaction_Login");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(20);
	
	//ѕроверка на успешную авторизацию
	web_reg_find("Text=Using the menu to the left", LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={Login}", ENDITEM,
		"Name=password", "Value={Password}", ENDITEM,
		"Name=login.x", "Value=26", ENDITEM,
		"Name=login.y", "Value=12", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("2_transaction_Login",LR_AUTO);

	lr_think_time(39);

	lr_start_transaction("3_transaction_ToFlights");
	
	//ѕроверка на переход страницы flight
	web_reg_find("Text=Departure City", LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_transaction_ToFlights",LR_AUTO);

	lr_start_transaction("4_transaction_Find_Flights");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(12);
	
	//ѕроверка на переход страницы с выбором билета
	web_reg_find("Text=Find Flight", LAST);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={CityFrom}", ENDITEM, 
		"Name=departDate", "Value={departDate2}", ENDITEM, 
		"Name=arrive", "Value={CityTo}", ENDITEM, 
		"Name=returnDate", "Value={returnDate2}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value={PlaceOfSeat}", ENDITEM, 
		"Name=seatType", "Value={TypeOfSeat}", ENDITEM, 
		"Name=findFlights.x", "Value=41", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("4_transaction_Find_Flights",LR_AUTO);

	lr_end_transaction("Full_transaction_SearchTicketNoBuy",LR_AUTO);

	return 0;
}