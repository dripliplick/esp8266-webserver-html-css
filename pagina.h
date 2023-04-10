const char pagina[] PROGMEM = R"=====(
      <!DOCTYPE html>
      <html>
      <head>
          <title>Web Server - Esp8266</title>
          <style>
        {
            margin: 0;
            pad: 0;
            box-sizing: border-box;
            font-family: 'Montserrat', sans-serif;
        }
        body{
            background-color: gray;
        }
        header{
            width: 100%;
            background-color: #lcle25; 
            display: all;
            align-items: center;
            
        }

        header .logo img{
            width: 100%;
            max-width: 300%;
            height: auto;
        }
        header .title{
            color: blue;
            font-size: 50px;
            display: ;
        }
        .container{
            width: 100%;
            max-width: 1300%;
            margin: 0 auto;
            display: flex;
        }

        section{
            background-color: darkgray;
            padding: 20px;
        }
        section .item-head{
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        section .titulo{
            color: aliceblue;
            font-size: 20px;
        }
        section .estado{
            font-size: 13px;
            padding: 3px;
            text-transform: uppercase;
        }
        /*pc*/
        @media (min-width: 700px){
            header justify-content: space-between;
            padding: 20px 60px 20px 60px;
        }
        .container{
            justify-content: center;
            padding: 20px 40px 20px 40px;
            flex-wrap: wrap;
        }
        section{
            width: 30%;
            margin: 20px;
        }
        /*mobile*/
        @media (max-width: 700px){
            header{
                justify-content: center;
                flex-direction: column;
                align-items: center;   
                padding: 30px 10px 20px 10px;
            }
            header .title{
                margin-top: 10px;
            }
            .container{
                padding: 20px;
                flex-direction: column;
            }
            .on{
                background-color: gray;
                color: black;
            }
            .off{
                background-color: gray;
                color: black;
            }
            section .acoes{
                width: 100%;
                padding-top: 20px;
                display: flex;
                justify-content: space-between;
            }
            section .acoes .ligar{
                width: 40%;
                height: 40px;
                background-color: gray;
                display: flex;
                justify-content: center;
                align-items: center;
                text-decoration: none;
                font-size: 15px;
                text-transform: uppercase;
                color: black;
                transition: all 0.4s;
            }
            section .acoes .ligar:hover{
                background-color: green;
            }
            section .acoes .desligar:hover{
                background-color: red;
            }
            section .acoes .desligar{
                width: 40%;
                height: 40px;
                background-color: gray;
                display: flex;
                justify-content: center;
                align-items: center;
                text-decoration: none;
                font-size: 15px;
                text-transform: uppercase;
                color: black;
        }
          </style>
      </head>
      <body>
          <header>
              <div class="logo">
                  <img src="https://picwishhk.oss-cn-hongkong.aliyuncs.com/tasks/output/segmentation/a76d99bc-66d5-4cb3-96e3-ee419d0d059f-image.png?Expires=1680952127&OSSAccessKeyId=LTAI5tGjJnh66c1txANiRBQN&Signature=Z9%2BxZb/uvH0GZrXxWJAlyGmUSk4%3D" alt="">
              </div>
              <div class="title">Web Server - Esp8266</div>   
          </header>
          <div class="container">
              <!-- Add your HTML code here -->
          </div>
          <footer>
              Feito por Joao!
          </footer>
      </body>
      </html>
    )=====";

const char rodape[] PROGMEM = R"=====(
      </div>
      <footer>
          Feito por Joao!
      </footer>
      </body>
      </html>
    )=====";