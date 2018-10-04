import React, {Component} from 'react';
import { connect } from 'react-redux';
import { updateUsers } from '../actions/creators/users';

class User extends Component {
    constructor(props) {
        super(props);

        this.onUpdateUser = this.onUpdateUser.bind(this);
    }
    onUpdateUser(evt) {
        this.props.onUpdateUser(evt.target.value);
    }
    render() {
        return (
            <div>
                <div>
                    {this.props.users} 
                </div>
                <div>
                    <input onChange={this.onUpdateUser} />
                </div>
            </div>
        )
    }
}

const mapStateToProps = ({products, users}) => ({
    products,
    users
})

const mapDispatchToProps = {
    onUpdateUser: updateUsers
}

export default connect(mapStateToProps, mapDispatchToProps)(User);