const http = require('http');
const fs = require('fs');
const port = 3000;
const { exec } = require('child_process');

const server = http.createServer(function(req, res) {
    if (req.url === '/page1') {
        fs.readFile('page1.html', function(err, data) {
            if (err) {
                res.writeHead(404);
                res.end('Error: File Not Found');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.write(data);
                res.end();
            }
        });
    } else if (req.url === '/display') {
        fs.readFile('display.html', function(err, htmlData) {
            if (err) {
                res.writeHead(404);
                res.end('Error: File Not Found');
            } else {

                exec('cd .. && cmake . && make && ./display', (error, stdout, stderr) => {
                    if (error) {
                        console.error(`Error: ${error.message}`);
                        return;
                    }
                    if (stderr) {
                        console.error(`stderr: ${stderr}`);
                        return;
                    }
                    console.log(`C++ program output: ${stdout}`);
                    
                    // Use the output (stdout) as needed in your JavaScript logic
                    // For instance, log it or pass it to another function
                    const processedData = processData(stdout);

                    // Replace a placeholder in index.html with the processed data
                    const modifiedHtml = htmlData.toString().replace('<!-- DATA_PLACEHOLDER -->', stdout);
                    console.log(stdout)
                    res.writeHead(200, { 'Content-Type': 'text/html' });
                    res.write(modifiedHtml);
                    res.end();
                });
                
                function processData(data) {
                    // Process the data here (e.g., log, manipulate, or send to client)
                    const lines = data.split('\n');
                    let processedData = '<ul>'; // Assuming you want to display the lines as a list
                    lines.forEach((line, index) => {
                        processedData += `<li>Line ${index + 1}: ${line}</li>`;
                    });
                    processedData += '</ul>';
                    return processedData;
                    // You can perform further operations or send this data to the client if this is a server-side script
                }


              
            }
        });

    } else if (req.url === '/admin') {
        fs.readFile('indexadmin.html', function(err, data) {
            if (err) {
                res.writeHead(404);
                res.end('Error: File Not Found');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.write(data);
                res.end();
            }
        });
    } else if (req.url === '/employee') {
        fs.readFile('indexemployee.html', function(err, data) {
            if (err) {
                res.writeHead(404);
                res.end('Error: File Not Found');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.write(data);
                res.end();
            }
        });
    } else if (req.url === '/login') {
        fs.readFile('indexlogin.html', function(err, data) {
            if (err) {
                res.writeHead(404);
                res.end('Error: File Not Found');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.write(data);
                res.end();
            }
        });
    } else if (req.method === 'POST' && req.url === '/submit') {
        let body = '';
        
        // Collect data sent from the form
        req.on('data', function(data) {
            body += data;
        });

        // When all data is received
        req.on('end', function() {
            const formData = JSON.parse(body); // Parse JSON data
            const dataArray = formData.dataArray;   // Extract the 'dataArray' field
            console.log('Data received:', dataArray);

            const userInput = dataArray.join(' '); // Join array elements into a string

            exec(`cd .. && cmake . && make && ./admin ${dataArray[0]} ${dataArray[1]} ${dataArray[2]} ${dataArray[3]}`, (error, stdout, stderr) => {
                if (error) {
                    console.error('Error:', error);
                    return res.status(500).send('Error occurred while executing the C++ program');
                }

                console.log('C++ program output:', stdout);
                res.write('Data sent to C++ program');

              
                res.end();
            });
        });
    } else if (req.method === 'POST' && req.url === '/submit_employee') {
        let body = '';
        
        // Collect data sent from the form
        req.on('data', function(data) {
            body += data;
        });

        // When all data is received
        req.on('end', function() {
            const formData = JSON.parse(body); // Parse JSON data
            const dataArray = formData.dataArray;   // Extract the 'dataArray' field
            console.log('Data received:', dataArray);

            const userInput = dataArray.join(' '); // Join array elements into a string

            exec(`cd .. && cmake . && make && ./admin ${dataArray[0]} ${dataArray[1]} ${dataArray[2]} ${dataArray[3]}`, (error, stdout, stderr) => {
                if (error) {
                    console.error('Error:', error);
                    return res.status(500).send('Error occurred while executing the C++ program');
                }

                console.log('C++ program output:', stdout);
                res.write('Data sent to C++ program');

              
                res.end();
            });
        });
    } else {
        res.writeHead(404);
        res.end('Error: Endpoint Not Found');
    } 
    
});

server.listen(port, function(error) {
    if (error) {
        console.log('Something went wrong', error);
    } else {
        console.log('Server is listening on port ' + port);
    }
});
