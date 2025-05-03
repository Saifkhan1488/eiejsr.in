// server.js
const express = require('express');
const bodyParser = require('body-parser');
const nodemailer = require('nodemailer');

const app = express();
const PORT = 3000;

// Replace with your email credentials
const transporter = nodemailer.createTransport({
  service: 'gmail',
  auth: {
    user: 'your.email@gmail.com',
    pass: 'your-app-password' // Use App Passwords, not real password
  }
});

app.use(bodyParser.json());

app.post('/github-webhook', (req, res) => {
  const event = req.headers['x-github-event'];
  const payload = req.body;

  console.log(`Received GitHub event: ${event}`);

  let subject = `GitHub Notification: ${event}`;
  let message = JSON.stringify(payload, null, 2);

  const mailOptions = {
    from: 'your.email@gmail.com',
    to: 'saifjsrali@gmail.com',
    subject: subject,
    text: message
  };

  transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
      console.error('Error sending email', error);
      return res.status(500).send('Error');
    }
    console.log('Email sent:', info.response);
    res.status(200).send('OK');
  });
});

app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
