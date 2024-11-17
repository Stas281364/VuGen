Action()
{

	lr_start_transaction("Full-transaction_SearchTicketNoBuy");

	lr_start_transaction("1_transaction_ToWebTours");

	web_add_cookie("MSO=SID&1730995019&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	//Проверка на загрузку формы логина
	web_reg_find("Text=Welcome to the Web Tours site", LAST);

/*Correlation comment - Do not change!  Original value='SID&1730995090&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10' Name ='MSO' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=MSO",
		"RegExp=MSO=(.*?);",
		SEARCH_FILTERS,
		"Scope=Cookies",
		"IgnoreRedirections=No",
		"RequestUrl=*/welcome.pl*",
		LAST);

/*Correlation comment - Do not change!  Original value='140218.314297286HcVctHQpftVzzzzHtDcHtpiHHcf' Name ='userSession' Type ='ResponseBased'*/
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

	lr_start_transaction("2_transaction_LogIn");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(20);
	
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

	lr_end_transaction("2_transaction_LogIn",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("3_transaction_ToFlights");
	
	//Проверка на переход страницы flight
	web_reg_find("Text=Departure City", LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("3_transaction_ToFlights",LR_AUTO);

	lr_start_transaction("4_transaction_СhooseTicket");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(12);
	
	//Проверка на переход страницы с выбором билета
	web_reg_find("Text=Find Flight", LAST);

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
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
		"Name=findFlights.x", "Value=49", ENDITEM,
		"Name=findFlights.y", "Value=17", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);

	lr_end_transaction("4_transaction_СhooseTicket",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("5_transaction_PaymentDetails");
	
	//Проверка на переход страницы с выбором билета
	web_reg_find("Text=Payment Details", LAST);

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value=030;251;11/08/2024", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=reserveFlights.x", "Value=77", ENDITEM,
		"Name=reserveFlights.y", "Value=9", ENDITEM,
		LAST);

	
	
	lr_end_transaction("5_transaction_PaymentDetails",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("6_transaction_EndBooking");
	
	//Проверка на переход страницы с выбором билета
	web_reg_find("Text=Invoice", LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={FirstName}", ENDITEM,
		"Name=lastName", "Value={LastName}", ENDITEM,
		"Name=address1", "Value=", ENDITEM,
		"Name=address2", "Value=", ENDITEM,
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM,
		"Name=creditCard", "Value={CreditData}", ENDITEM,
		"Name=expDate", "Value=09.09", ENDITEM,
		"Name=saveCC", "Value=on", ENDITEM,
		"Name=oldCCOption", "Value=on", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value=Coach", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=outboundFlight", "Value=030;251;11/08/2024", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=20", ENDITEM,
		"Name=buyFlights.y", "Value=3", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);

	lr_end_transaction("6_transaction_EndBooking",LR_AUTO);

	lr_end_transaction("Full-transaction_SearchTicketNoBuy",LR_AUTO);

	return 0;
}