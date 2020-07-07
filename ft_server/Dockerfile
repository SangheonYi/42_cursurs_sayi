FROM debian:buster
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install nginx

#nginx
RUN service nginx start
#nginx status
RUN service nginx status
#check browser or ping or curl localhost "Welcome to nginx!"

#self-signed ssl certification
RUN apt-get -y install openssl
RUN openssl req -newkey rsa:4096 -days 365 -node -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=yi/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN mv localhost.dev.crt etc/ssl/certs/
RUN mv localhost.dev.key etc/ssl/private/
RUN chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

