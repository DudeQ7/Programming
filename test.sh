Hi Simon,
Thank you for contacting support.
1. Connect via SSH to superbrands.com hosting,
2.Start a new session by typing ```
screen -S screen_name 
```,
3.Type in ```
goaccess logs/access.log -o httpdocs/report.html
```
4.  press  CTRL + A + D (this shortcut will detach you from the goaccess session)
If you wish to reconnect to the GoAccess screen later, use this command:
```
screen  -r screen_name
``` .
If you want to access this log with the up to date data, you 'll need to access this log over the HTTP not HTTPS:
http://www.superbrands.com/report.html.
If your .htaccess is forcing the HTTPS on the entire website,
you’ll need to create a rule that allows this specific URL to be accessed via HTTP. 
The same applies to:
```
https://www.casite-793510.cloudaccess.net/report.html
```
I went ahead and I applied those options to your hosting, 
Screen name is **goaccess **.

Please tell us if you need any further help.

Pawel Dutkiewicz | Joomla & WordPress Support Engineer | 231-421-7160
If you feel this ticket is solved, no reply is needed. This ticket will automatically close after 72 hours.