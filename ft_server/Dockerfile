FROM debian:buster
EXPOSE 80:80
EXPOSE 443:443
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install nginx vim curl wget

#nginx
RUN service nginx start
#check browser or ping or curl localhost "Welcome to nginx!"

#self-signed ssl certification
RUN apt-get -y install openssl
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=yi/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

COPY srcs/default.conf /etc/nginx/sites-available/default

#phpfpm, mariadb, mysql
RUN apt-get -y install php-fpm mariadb-server php-mysql
RUN service php7.3-fpm start
RUN service mysql start

#phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin
RUN mv phpmyadmin /var/www/html

COPY srcs/default.conf /etc/nginx/sites-available/default

#wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN mv wordpress/ var/www/html/
RUN chown -R www-data:www-data /var/www/html/wordpress
Grant all privileges on *.* to ‘user’@‘%’ identified by ‘ebdjf123’ with grant option;
flush privileges;
