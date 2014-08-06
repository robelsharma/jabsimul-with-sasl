jabsimul-with-sasl
==================

Jabsimul with SASL Integration is a benchmarking tool for Jabber/XMPP Servers which have SASL authentication.
It also has the support for starttls.

Special Note:
-------------

This project is not mine. 

Implementation:
---------------

I have implemented the protocol named XEP-0034: SASL Integration.

Extra Feature:
--------------

Other then jabsimul benchmark feature it has the extra feature of XMPP SASL authentication. I have enabled the SASL plain mechanism of authentication for xmpp login.

With that now you can have the benchmark of jabsimul with SASL authentication.



As list:

1. Implemented “XMPP TLS” from http://xmpp.org/rfcs/rfc3920.html
2. Implemented “SASL AUTH” from  http://xmpp.org/rfcs/rfc3920.html


Procedure:
----------

First start a TCP connection to the XMPP server. Then convert this TCP connection to TLS with *starttls* schema request.
Then select the *SASL* auth mechanism and start the the XMPP communication with TLS. The TLS connection holds when the SASL mechanism complete a successful handshake.


1. Protocol Messaging Details with sequence -


Client:
-------
```
<stream:stream to="intel.com" xmlns="jabber:client" xmlns:stream="http://etherx.jabber.org/streams">
```
Server:
-------
```
<stream:stream xmlns:stream='http://etherx.jabber.org/streams' xmlns='jabber:client' id='ojTsAaoSvVKdKfmW' from='intel.com'  version='1.0'>
<stream:features>
  <starttls xmlns="urn:ietf:params:xml:ns:xmpp-tls"><required/></starttls>
  <mechanisms xmlns="urn:ietf:params:xml:ns:xmpp-sasl">
    <mechanism>PLAIN</mechanism><mechanism>X-OAUTH2</mechanism>
  </mechanisms>
</stream:features>
```
Client:
-------
```
<starttls xmlns='urn:ietf:params:xml:ns:xmpp-tls'/>
```
Server:
-------
```
<proceed xmlns='urn:ietf:params:xml:ns:xmpp-tls'/>
```

Implementation details are available [here](https://developers.google.com/cloud-print/docs/rawxmpp)

How To's:
--------

cd jabsimul/jab_simul/
vi jab_simul.xml

Change *<server>jabber.localhost</server>* to your XMPP server address. Fill the xml file with you necessary configuration.

Compile it:

./configure
make


Now you can execute it:

./jab_simul
