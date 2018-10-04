import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import { connect } from 'react-redux';
import { updateUsers } from './actions/creators/users';

import User from './components/User';

class App extends Component {
  constructor(props) {
    super(props);
    this.onUpdateUser = this.onUpdateUser.bind(this);
  }
  onUpdateUser() {
    this.props.onUpdateUser("James");
  }
  render() {
    console.log(this.props)
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <h1 className="App-title">Welcome to React</h1>
        </header>
        <div onClick={this.onUpdateUser}>
          {this.props.users}
        </div>
        <User />
      </div>
    );
  }
}
const mapStateToProps = ({products, users}) => ({
  products,
  users
})
const mapDispatchToProps = {
  onUpdateUser:  updateUsers
}

export default connect(mapStateToProps, mapDispatchToProps)(App);
