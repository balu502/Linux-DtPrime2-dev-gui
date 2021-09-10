import QtQuick 2.3
import QtWebSockets 1.0

Rectangle
{

            id: main;
            width: 1;
            height: 1;
            color: "black"


        function subscribe()
           {
               if(!Web.connection_Server) return;

               var str = "subscribe:consumer data requested:consumer data available:consumer status requested:consumer cancel requested:amplif data available"
               var encodedString = Qt.btoa(str);
               var Str = "event:subscribe:client:rtapp:data:" + encodedString;

               Web.send_Message(str);
               return Str;
           }
		   
		   function getWebProtocol(id_protocol)
           {
               if(!Web.connection_Server) return;

               var str = "event:amplif data requested:subject:" + id_protocol;
               socket.sendTextMessage(str);
               Web.send_Message(str);
           }

		   /*
		   *	Запрос списка исполненных протоколов с сервера
		   * 	! 5 июля id_protocol=""
		   */
		   function getWebCompleted(id_protocol)
           {			
               if(!Web.connection_Server) return;

               var str = "event:consumer data requested:subject:" + id_protocol;
               socket.sendTextMessage(str);
               Web.send_Message(str);
           }		   
		   
           function send_ProtocolToWeb(id_protocol, data_protocol, name_protocol)
           {
               if(!Web.connection_Server) return;

               var str = Qt.btoa(data_protocol);
               var Str = "event:amplif data available:subject:" + id_protocol + ":data:";
               socket.sendTextMessage(Str + str);
               Web.send_Message(Str + " (" + name_protocol + ")");
           }

           function send_StateProtocolToWeb(id_protocol, state_protocol)
           {
               if(!Web.connection_Server) return;

               var message = " (" + id_protocol + ";" + state_protocol + ")";

               var str = ":data:" + Qt.btoa(state_protocol);
               var Str = "event:amplif status changed:subject:" + id_protocol + str;
               socket.sendTextMessage(Str);
               Web.send_Message(Str + message);
           }

           function set_StateSocket(state)
           {
               //socket.url = "ws://192.168.0.60:9002";


               socket.active = !socket.active; //state;
           }

           function set_SocketUrl(url)
           {
                socket.url = url;
           }

    WebSocket
    {
        id: socket
        url: ""
        active: true
	    property string connectionId: ""

        onStatusChanged:
               {
                   var str = "";

                   if(socket.status == WebSocket.Error)  console.log("Error: " + socket.errorString)
                   else
                   {
                       if(socket.status == WebSocket.Open)
                       {
                           print("web address: " + socket.url);

                           Web.url_Server = socket.url;
                           Web.connection_Server = true;

                           str = subscribe();
                           socket.sendTextMessage(str);
                       }
                       if(socket.status == WebSocket.Closed)
                       {
                           Web.connection_Server = false;
                       }
                   }
               }
	   // onTextMessageReceived:
	   // {
		   // var array_str = message.split(":");
		   // var event_type = array_str[1];
		   // var subject_type = array_str[array_str.indexOf("subject")+1]
		   // var str;
		   // var str_param = "";

		   // switch(event_type)
		   // {
			// default:                            break;

			// case "subscribe":                   break;
			// case "consumer data available":
				// {
					// str = Qt.atob(array_str[9]);
					// if(subject_type == ""){Web.get_ListProtocols(str,":"); str_param = " :List of Protocols";}
					// else {Web.get_Protocol(str); str_param = " :Protocol";}

					// break;
				// }
		   // }
		   // str = event_type + str_param;
		   // Web.get_Message(str);
		   // //print(message)
	   // }
			   
	   onTextMessageReceived:
		   {
			   var array_str = message.split(":");
			   var event_type = array_str[1];
			   var subject_type = array_str[array_str.indexOf( "subject")+1];
			   var rcr 			= array_str[array_str.indexOf("receiver")+1];
			   var sdr 			= array_str[array_str.indexOf(  "sender")+1];
			   var str;
			   var str_param = "";



			   switch(event_type)
			   {
				default:                            break;

				case "subscribe":
					{
						if ( (sdr==rcr) && !connectionId.length ){
							connectionId = rcr;
							print("Subscribed with id: " + connectionId);
						}
						break;
					}
				case "consumer data available":
					{
						str = Qt.atob(array_str[9]);
						
						if(subject_type == ""){		// получили список протоколов от сервера
								Web.get_ListProtocols(str,":"); 
								str_param = " :List of Protocols";
						}else {						
													// получили некий протокол от сервера, 
													// проверяем, если отправлено на наш connectionId, 
													// то обрабатываем
								if ( rcr == connectionId ){
									Web.get_Protocol(str); str_param = " :Protocol";
								}
						}

						//print(str);
						break;
					}
					
				case "amplif data available":
					{
						str = Qt.atob(array_str[9]);
						
						if(subject_type == ""){		// получили список исполненных протоколов от сервера
													// ! 5 июля
								Web.get_ListCompleted(str,":");		
								str_param = " :List of Protocols";
						}else {						
													// получили некий протокол от сервера, 
													// проверяем, если отправлено на наш connectionId, 
													// то обрабатываем
								/*
								if ( rcr == connectionId ){
									Web.get_Completed(str); str_param = " :Protocol";
								}
								*/
						}

						//print(str);
						break;
					}					
			   }
			   
			   // str = event_type + str_param;
			   // Web.get_Message(str);
			   //print(message)
		   }
			   
    }
}


