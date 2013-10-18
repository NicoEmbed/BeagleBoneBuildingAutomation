import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

msg = MIMEMultipart()
msg['From'] = 'nicolacolangiuliroma@gmail.com'
msg['To'] = 'nicocolangiuli@libero.it'
msg['Subject'] = 'simple email in python'
message = 'here is the email'
msg.attach(MIMEText(message))

mailserver = smtplib.SMTP('smtp.gmail.com',587)
# identify ourselves to smtp gmail client
mailserver.ehlo()
# secure our email with tls encryption
mailserver.starttls()
# re-identify ourselves as an encrypted connection
mailserver.ehlo()
mailserver.login('nicolacolangiuliroma@gmail.com', 'lavoroembedded')

mailserver.sendmail('nicolacolangiuliroma@gmail.com','nicocolangiuli@libero.it',msg.as_string())

mailserver.quit()