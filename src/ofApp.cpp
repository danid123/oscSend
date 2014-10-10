#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(40, 100, 40);

	// open an outgoing connection to HOST:PORT
	sender.setup(HOST, PORT);
    
    imgAsBuffer = ofBufferFromFile("sendImageTest.jpg", true);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(img.getWidth() > 0){
        ofDrawBitmapString("Image:", 10, 160);
        img.draw(10, 180);
    }
    
	// display instructions
	string buf;
	buf = "sending osc messages to" + string(HOST) + ofToString(PORT);
	ofDrawBitmapString(buf, 10, 20);
	ofDrawBitmapString("move the mouse to send osc message [/mouse/position <x> <y>]", 10, 50);
	ofDrawBitmapString("click to send osc message [/mouse/button <button> <\"up\"|\"down\">]", 10, 65);
	ofDrawBitmapString("press l to send osc message [/light light]", 10, 80);
	ofDrawBitmapString("press b to buzz [/buzz]", 10, 95);
    ofDrawBitmapString("press the spacebar to fire [/catapult]", 10, 110);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == ' '){
		ofxOscMessage m;
		m.setAddress("/catapult");
		m.addIntArg(1);
		m.addFloatArg(3.5f);
		m.addStringArg("fire");
		m.addFloatArg(ofGetElapsedTimef());
		sender.sendMessage(m);
	}
    if(key == 'l'){
		ofxOscMessage m;
		m.setAddress("/light");
		m.addIntArg(1);
		m.addFloatArg(3.5f);
		m.addStringArg("light");
		m.addFloatArg(ofGetElapsedTimef());
		sender.sendMessage(m);
	}
    if(key == 'b'){
		ofxOscMessage m;
		m.setAddress("/buzz");
		m.addIntArg(1);
		m.addFloatArg(3.5f);
		m.addStringArg("buzz");
		m.addFloatArg(ofGetElapsedTimef());
		sender.sendMessage(m);
	}
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	ofxOscMessage m;
	m.setAddress("/mouse/position");
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress("/mouse/button");
	m.addStringArg("down");
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofxOscMessage m;
	m.setAddress("/mouse/button");
	m.addStringArg("up");
	sender.sendMessage(m);

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

