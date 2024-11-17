Action()
{

	lr_start_transaction("Full_transaction_Regisrtation");

	lr_start_transaction("1_transaction_ToWebTors");

	web_add_cookie("MSO=SID&1731428649&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_add_cookie("MTUserInfo=firstName&Jojo&address2&&username&jojo&hash&47&lastName&Bean%0A&address1&&creditCard&123&expDate&09.09%0A; DOMAIN=localhost");

	web_add_auto_header("Priority", 
		"u=5");

	web_url("hp_logo.png", 
		"URL=http://localhost:1080/WebTours/images/hp_logo.png", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=http://localhost:1080/WebTours/header.html", 
		"Snapshot=t1.inf", 
		LAST);

	web_url("webtours.png", 
		"URL=http://localhost:1080/WebTours/images/webtours.png", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=http://localhost:1080/WebTours/header.html", 
		"Snapshot=t2.inf", 
		LAST);

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
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MSO=SID&1731604995&MSO_SLoad&on&MSO_SErrors&on&MSO_ServerErrorsProb&10&MSO_ServerLoadProb&10; DOMAIN=localhost");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("1_transaction_ToWebTors",LR_AUTO);

	lr_start_transaction("2_transaction_ToSingUp");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	lr_think_time(11);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("2_transaction_ToSingUp",LR_AUTO);

	lr_start_transaction("3_transaction_CustomerProfile");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(63);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=UserCustom", ENDITEM, 
		"Name=password", "Value=123", ENDITEM, 
		"Name=passwordConfirm", "Value=123", ENDITEM, 
		"Name=firstName", "Value=CustomFirstName", ENDITEM, 
		"Name=lastName", "Value=CustomLastName", ENDITEM, 
		"Name=address1", "Value=Gagarin", ENDITEM, 
		"Name=address2", "Value=Surgut", ENDITEM, 
		"Name=register.x", "Value=49", ENDITEM, 
		"Name=register.y", "Value=12", ENDITEM, 
		LAST);

	lr_end_transaction("3_transaction_CustomerProfile",LR_AUTO);

	lr_end_transaction("Full_transaction_Regisrtation",LR_AUTO);

	return 0;
}