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

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO=SID&1731428649&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	lr_end_transaction("1_transaction_ToWebTours",LR_AUTO);

	lr_start_transaction("2_transaction_Login");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(14);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=140253.434507898HcVtcizpADHftDcifpHVzccf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=0", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("2_transaction_Login",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("3_transaction_To_Itinerary");

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
		"Name=flightID", "Value=45556-7-JB", ENDITEM, 
		"Name=flightID", "Value=4557785-1554-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-2327-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-3096-JB", ENDITEM, 
		"Name=flightID", "Value=45555-38-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-4634-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-5403-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-6173-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-6942-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-7711-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-8480-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-9250-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-10019-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-10788-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-11557-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-12327-JB", ENDITEM, 
		"Name=flightID", "Value=45555-130-JB", ENDITEM, 
		"Name=flightID", "Value=45555-138-JB", ENDITEM, 
		"Name=flightID", "Value=45555-146-JB", ENDITEM, 
		"Name=flightID", "Value=45555-153-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-16173-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-16942-JB", ENDITEM, 
		"Name=flightID", "Value=45555-176-JB", ENDITEM, 
		"Name=flightID", "Value=45555-184-JB", ENDITEM, 
		"Name=flightID", "Value=45555-192-JB", ENDITEM, 
		"Name=flightID", "Value=4556675-20019-u", ENDITEM, 
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